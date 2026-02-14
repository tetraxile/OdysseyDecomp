#pragma once

#include <container/seadTList.h>

#include "Library/Draw/IUsePartsGraphics.h"

namespace al {

class GraphicsSystemInfo;

class PartsGraphics : public IUsePartsGraphics {
public:
    PartsGraphics(GraphicsSystemInfo* gfxSysInfo);

private:
    sead::TListNode<PartsGraphics*> mListNode;
};

static_assert(sizeof(PartsGraphics) == 0x28);

}  // namespace al
