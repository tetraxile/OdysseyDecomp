#include "Library/Controller/ReplayController.h"

#include "Library/Controller/IUsePadDataReader.h"
#include "Library/Controller/IUsePadDataWriter.h"
#include "Library/Controller/PadDataPack.h"

namespace al {

ReplayController::ReplayController(sead::Controller* controller) {
    registerWith(controller, true);
}

ReplayController::~ReplayController() {}

void ReplayController::unregist() {
    unregister();
}

void ReplayController::startReplay() {
    mIsReplaying = true;
}

void ReplayController::pauseReplay() {
    mIsReplaying = false;
}

void ReplayController::endReplay() {
    if (isReplaying() && mPadDataReader)
        mPadDataReader->close();

    mIsReplaying = false;
}

bool ReplayController::isReplaying() const {
    return mIsReplaying;
}

bool ReplayController::isRecording() const {
    return mIsRecording;
}

s32 ReplayController::getReplayRemainFrame() const {
    if (!mIsReplaying || !mPadDataReader)
        return 0;

    return mPadDataReader->getRemainFrame();
}

void ReplayController::calc(u32 prevHold, bool prevPointerOn) {
    mIsReadPadReplayData = false;
    sead::ControllerWrapperBase::calc(prevHold, prevPointerOn);

    if (isReplaying() && mPadDataReader) {
        PadDataPack frameData;
        mPadDataReader->read(&frameData);
        mPadTrig = frameData.mTrig;
        mPadHold = frameData.mHold;
        mLeftStick.set(frameData.mLeftStick);
        mPointer.set(frameData.mPointer);
        if (mPadDataReader->isEnd())
            endReplay();
        mIsReadPadReplayData = true;
    }

    if (isRecording() && mPadDataWriter) {
        PadDataPack frameData;
        frameData.mTrig = mPadTrig;
        frameData.mHold = mPadHold;
        frameData.mLeftStick.set(mLeftStick);
        frameData.mPointer.set(mPointer);
        mPadDataWriter->write(frameData);
    }
}

void ReplayController::startRecord() {
    if (!isRecording() && mPadDataWriter)
        mPadDataWriter->open();

    mIsRecording = true;
}

void ReplayController::endRecord() {
    if (isRecording() && mPadDataWriter)
        mPadDataWriter->close();

    mIsRecording = false;
}

}  // namespace al
