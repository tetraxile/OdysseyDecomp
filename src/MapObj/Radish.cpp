#include "MapObj/Radish.h"

#include "Library/Base/StringUtil.h"
#include "Library/Collision/PartsConnectorUtil.h"
#include "Library/Effect/EffectSystemInfo.h"
#include "Library/Item/ItemUtil.h"
#include "Library/Joint/JointControllerKeeper.h"
#include "Library/Joint/JointSpringController.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorAreaFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorFlagFunction.h"
#include "Library/LiveActor/ActorInitUtil.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorPoseUtil.h"
#include "Library/LiveActor/ActorSensorUtil.h"
#include "Library/Math/MathUtil.h"
#include "Library/Matrix/MatrixUtil.h"
#include "Library/Movement/FlashingCtrl.h"
#include "Library/Nerve/NerveSetupUtil.h"
#include "Library/Nerve/NerveUtil.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Player/PlayerUtil.h"

#include "Item/Shine.h"
#include "MapObj/MapObjStatePlayerHold.h"
#include "MapObj/PlayerHoldObjTutorialController.h"
#include "MapObj/Radish.h"
#include "Util/ItemUtil.h"
#include "Util/PlayerHackFunction.h"
#include "Util/PlayerUtil.h"
#include "Util/SensorMsgFunction.h"

namespace {
NERVE_IMPL(Radish, HideWait);
NERVE_IMPL(Radish, Hold);
NERVE_IMPL(Radish, HideReaction);
NERVE_IMPL(Radish, Throw);
NERVE_IMPL(Radish, Land);
NERVE_IMPL(Radish, Bound);
NERVE_IMPL(Radish, SaucePanInNoDemo);
NERVE_IMPL(Radish, ResetWait);
NERVE_IMPL(Radish, Reset);
NERVE_IMPL(Radish, Break);
NERVE_IMPL(Radish, SaucePanIn);
NERVE_IMPL(Radish, Wait);
NERVE_IMPL(Radish, Pull);
NERVE_IMPL(Radish, PullOut);
NERVE_IMPL_(Radish, ReactionTrample, Reaction);
NERVE_IMPL_(Radish, ReactionCap, Reaction);

NERVES_MAKE_STRUCT(Radish, HideWait, Hold, HideReaction, Throw, Land, Bound, SaucePanInNoDemo,
                   ResetWait, Reset, Break, SaucePanIn, Wait, Pull, PullOut, ReactionTrample,
                   ReactionCap);
}  // namespace

Radish::Radish(const char* name)
    : al::LiveActor(name),
      mTutorialController(new PlayerHoldObjTutorialController(this, "Radish", 350.0f)) {}

void Radish::init(const al::ActorInitInfo& info) {
    const char* objectName;
    al::tryGetObjectName(&objectName, info);
    mIsGold = al::isEqualString(objectName, "RadishGold");

    al::initActorWithArchiveName(this, info, objectName, nullptr);
    al::initNerve(this, &NrvRadish.HideWait, 1);

    mStatePlayerHold = new MapObjStatePlayerHold(this, {0.0f, 0.0f, 10.0f}, {0.0f, 0.0f, 0.0f});
    mStatePlayerHold->initUseColliderPush(1.0f);
    mStatePlayerHold->initShadowMaskDropLengthCtrl("カブ影");
    al::initNerveState(this, mStatePlayerHold, &NrvRadish.Hold, "ホールド");

    al::rotateQuatYDirDegree(this, al::getRandomDegree());
    al::offCollide(this);

    if (mIsGold) {
        mShine = rs::tryInitLinkShine(info, ShineFunction::getMovePointLinkName(), 0);
        if (mShine)
            rs::updateHintTrans(mShine, al::getTrans(this));
    } else
        mCoinAppearTimer = al::getRandom(10) + 1;

    mInitTrans = al::getTrans(this);
    mInitQuat = al::getQuat(this);
    mMtxConnector = al::tryCreateMtxConnector(this, info);
    mCapTargetInfo = rs::createCapTargetInfo(this, nullptr);

    al::initJointControllerKeeper(this, 2);
    al::initJointLocalYRotator(this, &_150, "CapPoint");
    mJointSpringController = al::initJointSpringController(this, "Reaf");
    mJointSpringController->setChildLocalPos({200.0f, 200.0f, 200.0f});
    mJointSpringController->setStability(0.1f);

    mFlashingCtrl = new al::FlashingCtrl(this, true, false);
    mAttackSensor = al::getHitSensor(this, "Attack");

    makeActorAlive();
}

void Radish::initAfterPlacement() {
    if (mMtxConnector)
        al::attachMtxConnectorToCollision(mMtxConnector, this, false);

    resetForHide();
}

void Radish::resetForHide() {
    al::hideSilhouetteModelIfShow(this);
    al::offCollide(this);
    al::setVelocityZero(this);
    sead::Vector3f pos = mInitTrans - 130.0f * sead::Vector3f::ey;
    al::resetPosition(this, pos);
}

void Radish::control() {
    if (_158 >= 0)
        _158--;

    if (mMtxConnector &&
        (al::isNerve(this, &NrvRadish.HideWait) || al::isNerve(this, &NrvRadish.HideReaction))) {
        al::connectPoseQT(this, mMtxConnector, mInitQuat, mInitTrans);
        resetForHide();
    }

    if (al::isNerve(this, &NrvRadish.HideWait) || al::isNerve(this, &NrvRadish.HideReaction)) {
        PlayerHoldObjTutorialController* controller = mTutorialController;
        controller->set_15(true);
        controller->update();
    } else {
        mTutorialController->set_15(false);
    }
    mTutorialController->update();

    if ((al::isNerve(this, &NrvRadish.Throw) || al::isNerve(this, &NrvRadish.Land) ||
         al::isNerve(this, &NrvRadish.Bound)) &&
        al::isCollidedFloorCode(this, "DamageFire")) {
        al::HitSensor* collidedGroundSensor = al::tryGetCollidedGroundSensor(this);
        if (collidedGroundSensor &&
            rs::sendMsgStartInSaucePan(collidedGroundSensor, al::getHitSensor(this, "Body"),
                                       mShine != nullptr)) {
            al::offCollide(this);
            al::setNerve(this, &NrvRadish.SaucePanInNoDemo);
            return;
        }
    }

    if (!al::isNerve(this, &NrvRadish.ResetWait) && !al::isNerve(this, &NrvRadish.Reset) &&
        !al::isNerve(this, &NrvRadish.SaucePanInNoDemo) &&
        !al::isNerve(this, &NrvRadish.SaucePanIn) && !al::isNerve(this, &NrvRadish.Hold)) {
        if (al::isInDeathArea(this)) {
            al::startHitReaction(this, "消滅");
            reset();
            return;
        } else if (al::isCollidedFloorCode(this, "DamageFire") ||
                   al::isCollidedFloorCode(this, "Needle") ||
                   al::isCollidedFloorCode(this, "Poison")) {
            al::updateMaterialCodeAll(this);
            al::startHitReaction(this, "消滅");
            reset();
            return;
        }
    }

    if (!mShine)
        return;

    if (al::isNerve(this, &NrvRadish.SaucePanInNoDemo) || al::isNerve(this, &NrvRadish.SaucePanIn))
        return;

    rs::updateHintTrans(mShine, al::getTrans(this));
}

void Radish::reset() {
    al::offCollide(this);
    al::invalidateHitSensors(this);
    al::hideModelIfShow(this);
    al::hideSilhouetteModelIfShow(this);
    al::invalidateClipping(this);
    al::setVelocityZero(this);
    al::setNerve(this, &NrvRadish.ResetWait);
}

void Radish::updateCollider() {
    if (mStatePlayerHold->isDead())
        al::LiveActor::updateCollider();
    else
        mStatePlayerHold->updateCollider(al::getHitSensor(this, "Body"));
}

void Radish::attackSensor(al::HitSensor* self, al::HitSensor* other) {
    if (!al::isSensorEnemyAttack(self))
        return;

    if (al::isNerve(this, &NrvRadish.ResetWait) || al::isNerve(this, &NrvRadish.Reset) ||
        al::isNerve(this, &NrvRadish.Break))
        return;

    if (al::isNerve(this, &NrvRadish.Hold))
        mStatePlayerHold->attackSensor(self, other);

    if (al::isNerve(this, &NrvRadish.Throw) || al::isNerve(this, &NrvRadish.Bound)) {
        if (al::isSensorMapObj(other))
            al::sendMsgBallItemGet(other, self);

        if ((al::isSensorEnemyBody(other) || al::isSensorNpc(other) || al::isSensorMapObj(other)) &&
            !_154) {
            if (rs::sendMsgRadishReflect(other, self)) {
                const sead::Vector3f& otherPos = al::getSensorPos(other);
                const sead::Vector3f& selfPos = al::getSensorPos(self);
                sead::Vector3f selfToOther = {otherPos.x - selfPos.x, 0.0f, otherPos.z - selfPos.z};

                if (!al::tryNormalizeOrZero(&selfToOther))
                    selfToOther.set(sead::Vector3f::ez);

                if (al::getVelocity(this).dot(selfToOther) > 0.0f)
                    al::verticalizeVec(al::getVelocityPtr(this), selfToOther,
                                       al::getVelocity(this));

                _154 = true;
                return;
            }

            if (rs::sendMsgRadishAttack(other, self))
                return;
        }
    }

    if (al::isNerve(this, &NrvRadish.SaucePanInNoDemo) ||
        al::isNerve(this, &NrvRadish.SaucePanIn) || al::isNerve(this, &NrvRadish.HideWait) ||
        al::isNerve(this, &NrvRadish.HideReaction) || al::isNerve(this, &NrvRadish.Hold))
        return;

    if (!al::sendMsgPushAndKillVelocityToTarget(this, self, other))
        rs::sendMsgPushToPlayer(other, self);
}

bool Radish::receiveMsg(const al::SensorMsg* message, al::HitSensor* other, al::HitSensor* self) {
    if (rs::tryReceiveMsgInitCapTargetAndSetCapTargetInfo(message, mCapTargetInfo))
        return true;

    if (!al::isNerve(this, &NrvRadish.Hold) && !al::isNerve(this, &NrvRadish.Bound) &&
        al::isMsgBlockUpperPunch(message)) {
        al::addVelocity(this, {0.0f, 15.0f, 0.0f});
        al::setNerve(this, &NrvRadish.Bound);
        return true;
    }

    if (rs::isMsgKillByHomeDemo(message)) {
        if (al::isNerve(this, &NrvRadish.Hold))
            mStatePlayerHold->tryCancelHold(self);

        reset();
        return true;
    }

    if (!al::isSensorMapObj(self))
        return false;

    if (al::isNerve(this, &NrvRadish.ResetWait) || al::isNerve(this, &NrvRadish.Reset) ||
        al::isNerve(this, &NrvRadish.Break))
        return false;

    if (rs::isMsgKillByShineGet(message)) {
        if (al::isNerve(this, &NrvRadish.Hold))
            return false;

        if (!al::isNerve(this, &NrvRadish.Reset) && !al::isNerve(this, &NrvRadish.ResetWait) &&
            !al::isNerve(this, &NrvRadish.SaucePanInNoDemo) &&
            !al::isNerve(this, &NrvRadish.SaucePanIn)) {
            reset();
            return true;
        }
    }

    if (al::isNerve(this, &NrvRadish.HideWait) && al::isMsgPlayerObjTouch(message)) {
        if (_158 > 0)
            return false;

        al::setNerve(this, &NrvRadish.HideReaction);
        return true;
    }

    if ((al::isNerve(this, &NrvRadish.Wait) || al::isNerve(this, &NrvRadish.Bound) ||
         al::isNerve(this, &NrvRadish.Land)) &&
        al::tryReceiveMsgPushAndAddVelocityH(this, message, other, self, 5.0f))
        return true;

    if (al::isMsgPush(message))
        return true;

    if (al::isNerve(this, &NrvRadish.Hold)) {
        if (al::isMsgPlayerDisregard(message))
            return true;

        if (al::isMsgPlayerReleaseDemo(message)) {
            release(2);
            reset();
            return true;
        }

        if (mStatePlayerHold->receiveMsgNoRelease(message, other, self))
            return true;

        if (mStatePlayerHold->receiveMsgRelease(message, other, self)) {
            if (al::isMsgPlayerReleaseBySwing(message)) {
                release(1);
                return true;
            }

            release(al::isMsgPlayerRelease(message) ? 0 : 2);
            return true;
        }
    }

    if (rs::isMsgEndInSaucePan(message) && al::isNerve(this, &NrvRadish.SaucePanInNoDemo)) {
        al::invalidateClipping(this);
        al::setNerve(this, &NrvRadish.SaucePanIn);
        return true;
    }

    if (rs::isMsgCapKeepLockOn(message)) {
        return al::isNerve(this, &NrvRadish.HideWait) ||
               al::isNerve(this, &NrvRadish.HideReaction) || al::isNerve(this, &NrvRadish.Pull);
    }

    if (al::isNerve(this, &NrvRadish.Pull) && rs::isMsgCapIgnoreCancelLockOn(message))
        return true;

    if (rs::isMsgCapCancelLockOn(message))
        return true;

    if (rs::isMsgCapStartLockOn(message) &&
        (al::isNerve(this, &NrvRadish.HideWait) || al::isNerve(this, &NrvRadish.HideReaction))) {
        al::invalidateClipping(this);
        al::setNerve(this, &NrvRadish.Pull);
        return true;
    }

    if (al::isNerve(this, &NrvRadish.HideWait) || al::isNerve(this, &NrvRadish.HideReaction))
        return false;

    if (mStatePlayerHold->tryStartCarryUp(message, other) &&
        (al::isNerve(this, &NrvRadish.Wait) || al::isNerve(this, &NrvRadish.ReactionCap) ||
         al::isNerve(this, &NrvRadish.ReactionTrample) || al::isNerve(this, &NrvRadish.Land) ||
         (al::isNerve(this, &NrvRadish.PullOut) && al::isGreaterEqualStep(this, 10)))) {
        al::setNerve(this, &NrvRadish.Hold);
        return true;
    }

    if (rs::isMsgBubbleAttack(message) || rs::isMsgFireDamageAll(message)) {
        if (al::isNerve(this, &NrvRadish.Hold))
            mStatePlayerHold->tryCancelHold(self);

        rs::requestHitReactionToAttacker(message, self, other);
        al::startHitReaction(this, "消滅");
        reset();
        return true;
    }

    if ((rs::isMsgHammerBrosHammerEnemyAttack(message) ||
         rs::isMsgHammerBrosHammerHackAttack(message)) &&
        !(al::isNerve(this, &NrvRadish.HideWait) || al::isNerve(this, &NrvRadish.HideReaction))) {
        if (al::isNerve(this, &NrvRadish.Hold))
            mStatePlayerHold->tryCancelHold(self);

        rs::requestHitReactionToAttacker(message, self, other);
        al::setNerve(this, &NrvRadish.Break);
        return true;
    }

    if (!al::isNerve(this, &NrvRadish.Wait) && !al::isNerve(this, &NrvRadish.ReactionCap) &&
        !al::isNerve(this, &NrvRadish.ReactionTrample)) {
        return rs::isMsgCapReflect(message);
    }

    if (_158 > 0)
        return false;

    if (mIsGold) {
        if (rs::isMsgPlayerAndCapObjHipDropReflectAll(message)) {
            rs::requestHitReactionToAttacker(message, self, other);
            al::startHitReaction(this, "ヒップドロップ");
            al::setNerve(this, &NrvRadish.ReactionTrample);
            return true;
        }
    } else if (rs::isMsgPlayerAndCapObjHipDropAll(message)) {
        rs::requestHitReactionToAttacker(message, self, other);
        al::appearItemTiming(this, "ヒップドロップ");
        al::setNerve(this, &NrvRadish.Break);
        return true;
    }

    if (al::isMsgPlayerTrampleReflect(message)) {
        rs::requestHitReactionToAttacker(message, self, other);
        al::setNerve(this, &NrvRadish.ReactionTrample);
        return true;
    }

    if (rs::isMsgCapReflect(message)) {
        rs::requestHitReactionToAttacker(message, self, other);
        al::setNerve(this, &NrvRadish.ReactionCap);
        return true;
    }

    return false;
}

void Radish::release(s32 throwType) {
    bool isBlah = throwType == 2;

    sead::Vector3f frontDir;
    rs::calcPlayerFrontDir(&frontDir, this);
    const sead::Vector3f& gravity = al::getGravity(this);
    al::verticalizeVec(&frontDir, gravity, frontDir);
    al::tryNormalizeOrDirZ(&frontDir);

    f32 throwPowers[2] = {35.0f, 45.0f};
    f32 throwPower = isBlah ? 80.0f : throwPowers[throwType == 1];

    sead::Vector3f balls = -al::getGravity(this);
    al::turnVecToVecDegree(&frontDir, frontDir, balls, throwPower);
    al::normalize(&frontDir);

    sead::Matrix34f boalls;
    al::makeMtxUpFrontPos(&boalls, sead::Vector3f::ey, frontDir, al::getTrans(this));
    al::updatePoseMtx(this, &boalls);

    if (throwType == 2) {
        al::setVelocityToDirection(this, frontDir, 12.0f);
    } else {
        al::setVelocityToDirection(this, frontDir, throwType == 1 ? 40.0f : 25.0f);
        sead::Vector3f vel = rs::getPlayerVelocity(this);
        vel.y = 0.0f;
        al::addVelocity(this, vel);
    }

    al::onCollide(this);
    al::setNerve(this, &NrvRadish.Throw);
}

void Radish::pull() {
    al::invalidateClipping(this);
    al::setNerve(this, &NrvRadish.Pull);
}

void Radish::exeHideWait() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Wait");
        al::validateClipping(this);
        al::offCollide(this);
    }
}

void Radish::exeHideReaction() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "ReactionUnderground");
        _158 = 10;
    }

    if (al::isActionEnd(this))
        al::setNerve(this, &NrvRadish.HideWait);
}

void Radish::exePull() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Pull");
        sead::Vector3f capPointPos = {0.0f, 0.0f, 0.0f};
        al::calcJointPos(&capPointPos, this, "CapPoint");
        sead::Vector3f toCapPoint = al::getPlayerPos(this, 0) - capPointPos;
        if (al::tryNormalizeOrZero(&toCapPoint)) {
            sead::Vector3f capPointUpDir = {0.0f, 0.0f, 0.0f};
            sead::Vector3f capPointFrontDir = {0.0f, 0.0f, 0.0f};
            al::calcJointUpDir(&capPointUpDir, this, "CapPoint");
            al::calcJointFrontDir(&capPointFrontDir, this, "CapPoint");
            _150 = al::wrapAngle(
                al::calcAngleOnPlaneDegree(capPointFrontDir, toCapPoint, capPointUpDir));
        }
    }

    if (al::isActionEnd(this))
        al::setNerve(this, &NrvRadish.PullOut);
}

void Radish::exePullOut() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Pullout");
        al::setVelocityY(this, 32.0f);
    }

    al::scaleVelocity(this, 1.0f);
    al::addVelocityToGravity(this, 1.6f);

    if (al::isGreaterStep(this, 5)) {
        if (al::isOnGround(this, 0))
            al::setNerve(this, &NrvRadish.Land);
    } else if (al::isStep(this, 5))
        al::onCollide(this);
}

void updateVelocity(al::LiveActor* actor, bool isGrounded) {
    if (isGrounded && al::isOnGround(actor, 0)) {
        al::scaleVelocity(actor, 0.08f);
        const sead::Vector3f& normal = al::getOnGroundNormal(actor, 0);
        const sead::Vector3f& velocity = al::getVelocity(actor);
        sead::Vector3f newVel = sead::Vector3f(velocity.x, 0.0f, velocity.z) - normal * 1.6f;
        al::setVelocity(actor, newVel);
        return;
    }

    al::scaleVelocity(actor, 1.0f);
    al::addVelocityToGravity(actor, 1.6f);
}

void Radish::exeWait() {
    if (al::isFirstStep(this)) {
        al::invalidateClipping(this);
        al::startAction(this, "WaitGround");
        al::setVelocityZero(this);
        mFlashingCtrl->start(1200);
    }

    updateVelocity(this, true);
    mFlashingCtrl->movement();

    if (mFlashingCtrl->isFinish()) {
        al::startHitReaction(this, "消滅");
        reset();
    }
}

void Radish::exeHold() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Wait");
        al::setVelocityZero(this);
        al::showModelIfHide(this);
        al::showSilhouetteModelIfHide(this);
    }

    al::updateNerveState(this);
}

void Radish::exeThrow() {
    if (al::isFirstStep(this)) {
        al::invalidateClipping(this);
        al::hideSilhouetteModelIfShow(this);
        mCollidedWallSensor = nullptr;
    }

    al::scaleVelocity(this, 1.0f);
    al::addVelocityToGravity(this, 1.6f);

    al::HitSensor* collidedWallSensor = al::tryGetCollidedWallSensor(this);
    if (collidedWallSensor)
        rs::sendMsgRadishAttack(collidedWallSensor, mAttackSensor);

    trySendBoundMsgToSaucePan();

    bool isOnGround = al::isOnGround(this, 0);
    if (collidedWallSensor || isOnGround) {
        mCollidedWallSensor = collidedWallSensor;
        al::setNerve(this, &NrvRadish.Bound);
    }
}

bool Radish::trySendBoundMsgToSaucePan() {
    al::HitSensor* collidedSensor = al::tryGetCollidedSensor(this);
    if (collidedSensor &&
        rs::sendMsgRadishReflect(collidedSensor, al::getHitSensor(this, "Body"))) {
        mCollidedSensor = collidedSensor;
        return true;
    }

    return false;
}

void Radish::exeBound() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Reaction");
        if (al::isOnGround(this, 0)) {
            sead::Vector3f normal = al::getOnGroundNormal(this, 0);
            sead::Vector3f sideDir;
            al::calcSideDir(&sideDir, this);
            sead::Vector3f trans = al::getTrans(this);
            al::makeMtxUpSidePos(&_15c, normal, sideDir, trans);
            al::setEffectFollowMtxPtr(this, "LandSmoke", &_15c);
            al::emitEffect(this, "LandSmoke", nullptr);
        }
        al::startHitReaction(this, "バウンド");
    }

    al::scaleVelocity(this, 1.0f);
    al::addVelocityToGravity(this, 1.6f);

    bool isOnGround = al::isOnGround(this, 0);
    al::HitSensor* collidedWallSensor = al::tryGetCollidedWallSensor(this);
    if (!isOnGround && !collidedWallSensor)
        return;

    if (al::isCollidedFloorCode(this, "DamageFire"))
        return;

    trySendBoundMsgToSaucePan();

    if (isOnGround) {
        if (al::reboundVelocityFromCollision(this, 0.3f, 15.0f, 0.3f))
            al::setNerve(this, &NrvRadish.Bound);
        else {
            al::setVelocityZeroH(this);
            al::setNerve(this, &NrvRadish.Land);
        }
        return;
    }

    if (collidedWallSensor && al::reboundVelocityFromCollision(this, 0.3f, 15.0f, 0.3f) &&
        collidedWallSensor != mCollidedWallSensor) {
        mCollidedWallSensor = collidedWallSensor;
        al::setNerve(this, &NrvRadish.Bound);
    }
}

void Radish::exeLand() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Land");
        al::setVelocityZero(this);
        _154 = false;

        if (al::isOnGround(this, 0)) {
            sead::Vector3f normal = al::getOnGroundNormal(this, 0);
            sead::Vector3f sideDir;
            al::calcSideDir(&sideDir, this);
            sead::Vector3f trans = al::getTrans(this);
            al::makeMtxUpSidePos(&_15c, normal, sideDir, trans);
            al::setEffectFollowMtxPtr(this, "LandSmoke", &_15c);
            al::emitEffect(this, "LandSmoke", nullptr);
        }
    }

    if (mCollidedSensor) {
        al::scaleVelocity(this, 0.87f);
        al::addVelocityToGravity(this, 1.6f);
    } else {
        updateVelocity(this, true);
    }

    if (al::isActionEnd(this)) {
        mCollidedSensor = nullptr;
        al::setNerve(this, &NrvRadish.Wait);
    }
}

void Radish::exeSaucePanInNoDemo() {
    if (al::isFirstStep(this)) {
        al::offCollide(this);
        al::hideSilhouetteModelIfShow(this);
    }
}

void Radish::exeSaucePanIn() {
    if (al::isFirstStep(this)) {
        al::setVelocityZero(this);
        al::hideModelIfShow(this);
        sead::Vector3f newPos = al::getTrans(this) + 280.0f * sead::Vector3f::ey;
        al::setTrans(this, newPos);
    }

    if (mIsGold) {
        al::setTrans(mShine, al::getTrans(this));
        mShine->appearPopupDelay(0);
        rs::updateHintTrans(mShine, al::getTrans(mShine));
    } else {
        if (al::getNerveStep(this) % 5 == 0) {
            al::appearItemTiming(this, "鍋にイン");
            mCoinAppearTimer--;
        }

        if (mCoinAppearTimer > 0)
            return;
    }

    kill();
}

void Radish::exeReaction() {
    if (al::isFirstStep(this)) {
        al::startAction(this, al::isNerve(this, &NrvRadish.ReactionCap) ? "ReactionCap" :
                                                                          "ReactionTrample");
        al::showModelIfHide(this);
        _158 = 10;
    }

    updateVelocity(this, true);
    if (al::isActionEnd(this))
        al::setNerve(this, &NrvRadish.Wait);
}

void Radish::exeBreak() {
    if (al::isFirstStep(this)) {
        al::startHitReaction(this, "破壊");
        al::setVelocityZero(this);
        al::showModelIfHide(this);
    }

    reset();
}

void Radish::exeResetWait() {
    if (al::isGreaterEqualStep(this, 60)) {
        al::validateHitSensors(this);
        al::setTrans(this, mInitTrans);
        al::setQuat(this, mInitQuat);
        al::resetPosition(this);
        al::rotateQuatYDirDegree(this, al::getRandomDegree());
        mInitQuat = al::getQuat(this);
        al::setNerve(this, &NrvRadish.Reset);
    }
}

void Radish::exeReset() {
    if (al::isFirstStep(this)) {
        al::startAction(this, "Reset");
        al::showModel(this);
        resetForHide();
        al::resetMaterialCode(this);
    }

    if (al::isActionEnd(this))
        al::setNerve(this, &NrvRadish.HideWait);
}
