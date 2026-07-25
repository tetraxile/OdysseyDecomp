#pragma once

#include <basis/seadTypes.h>

namespace al {
class LiveActor;
}

class PlayerHoldObjTutorialController {
public:
    PlayerHoldObjTutorialController(al::LiveActor* actor, const char*, f32);
    void update();

    void set_15(bool value) { _15 = value; }

private:
    al::LiveActor* mActor = nullptr;
    const char* mName = nullptr;
    f32 _10 = 0.0f;
    bool _14 = false;
    bool _15 = false;
};

static_assert(sizeof(PlayerHoldObjTutorialController) == 0x18);
