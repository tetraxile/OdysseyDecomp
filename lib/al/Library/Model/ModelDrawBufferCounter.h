#pragma once

#include <basis/seadTypes.h>

namespace al {

struct ModelDrawBufferCounter {
    u32 mDisplayListCount;
    u32 mDrawBufferIndex;
};

static_assert(sizeof(ModelDrawBufferCounter) == 0x8);

}
