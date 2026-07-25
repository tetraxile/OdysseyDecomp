#pragma once

#include <basis/seadTypes.h>

namespace al {
class LiveActor;

class FlashingCtrl {
public:
    FlashingCtrl(LiveActor*, bool, bool);

    virtual void movement();

    void end();
    bool isNowFlashing() const;
    void updateFlashing();
    void start(s32);
    s32 getInterval() const;
    f32 getFlashingAnimRate() const;
    bool isNowJustFlashed() const;
    bool isNowOn() const;

    bool isFinish() const { return mIsFinish; }

private:
    LiveActor* mActor;
    bool _10;
    bool mIsFinish;
    bool _12;
    s32 _14;
    s32 _18;
    bool _1c;
};

static_assert(sizeof(FlashingCtrl) == 0x20);
}  // namespace al
