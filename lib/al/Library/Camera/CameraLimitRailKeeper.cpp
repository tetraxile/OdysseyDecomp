#include "Library/Camera/CameraLimitRailKeeper.h"
#include "Library/Camera/CameraPoser.h"
#include "Library/Camera/CameraPoserFunction.h"
#include "Library/Math/MathUtil.h"
#include "Library/Placement/PlacementFunction.h"
#include "Library/Rail/Rail.h"
#include "Library/Rail/RailRider.h"
#include "math/seadVectorCalcCommon.h"

namespace al {

CameraLimitRailKeeper::CameraLimitRailKeeper() {}

void CameraLimitRailKeeper::init(const PlacementInfo& info, s32 viewCount) {
    mRail = new Rail();
    mRail->init(info);

    mRiderCount = viewCount;
    mRiders = new RailRider*[viewCount];
    for (s32 i = 0; i < mRiderCount; i++)
        mRiders[i] = new RailRider(mRail);

    tryGetArg(&mCameraLookAtDir, info, "CameraLookAtDir");
    tryGetArg(&mActivateDistance, info, "ActivateDistance");
    tryGetArg(&mDegreeMargin, info, "DegreeMargin");
    tryGetArg(&mAngleElevation, info, "AngleElevation");
    if (tryGetArg(&mAngleElevation2, info, "AngleElevation2")) {
        f32 tmp = mAngleElevation;
        if (tmp > mAngleElevation2) {
            mAngleElevation = mAngleElevation2;
            mAngleElevation2 = tmp;
        }
    } else {
        mAngleElevation2 = mAngleElevation;
    }

    tryGetArg(&mAngleElevationInterpStep, info, "AngleElevationInterpStep");
    tryGetArg(&mAngleElevationResetStep, info, "AngleElevationResetStep");
    tryGetArg(&mIsApplyAngleElevation, info, "IsApplyAngleElevation");
    tryGetArg(&mIsResetAngleElevation, info, "IsResetAngleElevation");
    tryGetArg(&mIsFixedAngle, info, "IsFixedAngle");

    tryGetArg(&mIsApplyCameraDistance, info, "IsApplyCameraDistance");
    if (mIsApplyCameraDistance) {
        tryGetArg(&mCameraDistance, info, "CameraDistance");
        tryGetArg(&mIsApplyCameraDistanceRange, info, "IsApplyCameraDistanceRange");
        if (mIsApplyCameraDistanceRange) {
            tryGetArg(&mCameraDistanceMin, info, "CameraDistanceMin");
            tryGetArg(&mCameraDistanceMax, info, "CameraDistanceMax");
        } else {
            mCameraDistanceMin = mCameraDistance;
            mCameraDistanceMax = mCameraDistance;
        }
    }

    tryGetArg(&mIsApplyOffsetY, info, "IsApplyOffsetY");
    if (mIsApplyOffsetY)
        tryGetArg(&mOffsetY, info, "OffsetY");

    tryGetArg(&mIsInvalidCheckCollision, info, "IsInvalidCheckCollision");
}

void CameraLimitRailKeeper::updateRider(const CameraPoser* poser) {
    getRider(poser)->setCoord(mRail->calcNearestRailPosCoord(poser->getTargetTrans(), 7.5f));
}

RailRider* CameraLimitRailKeeper::getRider(const CameraPoser* poser) const {
    s32 riderIdx = alCameraPoserFunction::getViewIndex(poser);
    return mRiders[riderIdx];
}

void CameraLimitRailKeeper::calcCameraDirH(sead::Vector3f* out, const CameraPoser* poser) const {
    sead::Vector3f dirH = {poser->getPosition().x - poser->getTargetTrans().x, 0.0f,
                           poser->getPosition().z - poser->getTargetTrans().z};
    normalize(&dirH);

    if (isNearInsideRailPoint(poser, 10.0f)) {
        *out = poser->getTargetTrans() - getRider(poser)->getPosition();
        verticalizeVec(out, sead::Vector3f::ey, *out);
        if (tryNormalizeOrZero(out))
            return;
        out->set(dirH);
        return;
    }

    sead::Vector3f dir = getRider(poser)->getDirection();
    dir.y = 0.0f;
    tryNormalizeOrDirZ(&dir);

    sead::Vector3f blah;
    blah.setCross(dir, poser->getCameraUp());
    if (!tryNormalizeOrZero(&blah))
        blah.x = 1.0f;

    out->set(mCameraLookAtDir == 6 ? blah : dir);

    if (mCameraLookAtDir == 0 || mCameraLookAtDir == 3 ||
        (calcAngleDegree(dirH, *out) > 90.0f && (mCameraLookAtDir == 5 || mCameraLookAtDir == 2))) {
        out->negate();
    }
}

bool CameraLimitRailKeeper::isNearInsideRailPoint(const CameraPoser* poser, f32 approx) const {
    f32 coord = getRider(poser)->getCoord();
    if (!mRail->isClosed() && (coord < approx || mRail->getTotalLength() - approx < coord))
        return false;

    return mRail->isNearRailPoint(coord, approx);
}

const sead::Vector3f& CameraLimitRailKeeper::getRailPos(const CameraPoser* poser) const {
    return getRider(poser)->getPosition();
}

f32 CameraLimitRailKeeper::calcDistanceFromNearestRailPos(const sead::Vector3f& pos) const {
    sead::Vector3f nearestPos = {0.0f, 0.0f, 0.0f};
    calcNearestRailPos(&nearestPos, pos);
    return (nearestPos - pos).length();
}

void CameraLimitRailKeeper::calcNearestRailPos(sead::Vector3f* out,
                                               const sead::Vector3f& pos) const {
    mRail->calcNearestRailPos(out, pos, 7.5f);
}

}  // namespace al
