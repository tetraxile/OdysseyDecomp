#include "Library/Controller/NpadController.h"

#include <controller/seadControllerMgr.h>
#include "controller/nin/seadNinJoyNpadDevice.h"

namespace al {

NpadController::NpadController(sead::ControllerMgr* controllerMgr)
    : sead::Controller(controllerMgr) {
    mId = sead::ControllerDefine::cController_Npad;
    setLeftStickCrossThreshold(0.9f, 0.7f);
    setRightStickCrossThreshold(0.9f, 0.7f);
}

bool NpadController::isConnected() const {
    return isValidNpadId() && mIsConnected;
}

bool NpadController::isValidNpadId() const {
    return mNpadId != -1;
}

s32 NpadController::getNpadId() const {
    return mNpadId;
}

void NpadController::setAnyControllerMode() {
    mControllerMode = -1;
}

void NpadController::setIndexControllerMode(s32 idx) {
    mControllerMode = idx;
}

nn::hid::VibrationDeviceHandle* NpadController::getVibrationDeviceHandle(s32 idx) const {
    auto* device = sead::ControllerMgr::instance()->getControlDeviceAs<sead::NinJoyNpadDevice*>();

    sead::NinJoyNpadDevice::NpadState& state = device->getNpadState(mNpadId);

    return &state.mVibrationDeviceHandles[idx];
}

}  // namespace al
