#include "Library/Play/Graphics/PartsGraphics.h"

#include "Library/Draw/GraphicsSystemInfo.h"

namespace al {

PartsGraphics::PartsGraphics(GraphicsSystemInfo* gfxSysInfo)
    : sead::TListNode<PartsGraphics*>(this) {
    gfxSysInfo->registPartsGraphics(this);
}

}  // namespace al
