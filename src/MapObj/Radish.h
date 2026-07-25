#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include <Library/LiveActor/LiveActor.h>

namespace al {
class MtxConnector;
class JointSpringController;
class FlashingCtrl;
}  // namespace al

class MapObjStatePlayerHold;
class Shine;
class CapTargetInfo;
class PlayerHoldObjTutorialController;

class Radish : public al::LiveActor {
public:
    Radish(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    void updateCollider() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

    void resetForHide();
    void reset();
    void release(s32);
    void pull();
    bool trySendBoundMsgToSaucePan();

    void exeHideWait();
    void exeHideReaction();
    void exePull();
    void exePullOut();
    void exeWait();
    void exeHold();
    void exeThrow();
    void exeBound();
    void exeLand();
    void exeSaucePanInNoDemo();
    void exeSaucePanIn();
    void exeReaction();
    void exeBreak();
    void exeResetWait();
    void exeReset();

private:
    MapObjStatePlayerHold* mStatePlayerHold = nullptr;
    bool mIsGold = false;
    s32 mCoinAppearTimer = 0;
    Shine* mShine = nullptr;
    sead::Vector3f mInitTrans = sead::Vector3f::zero;
    sead::Quatf mInitQuat = sead::Quatf::unit;
    al::MtxConnector* mMtxConnector = nullptr;
    CapTargetInfo* mCapTargetInfo = nullptr;
    f32 _150 = 0.0f;
    bool _154 = false;
    s32 _158 = -1;
    sead::Matrix34f _15c = sead::Matrix34f::ident;
    al::FlashingCtrl* mFlashingCtrl = nullptr;
    al::JointSpringController* mJointSpringController = nullptr;
    PlayerHoldObjTutorialController* mTutorialController = nullptr;
    al::HitSensor* mAttackSensor = nullptr;
    void* _1b0 = nullptr;
    void* _1b8 = nullptr;
    al::HitSensor* mCollidedSensor = nullptr;
    al::HitSensor* mCollidedWallSensor = nullptr;
};

static_assert(sizeof(Radish) == 0x1d0);
