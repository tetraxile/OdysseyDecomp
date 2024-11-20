#pragma once

namespace agl {
class DrawContext;
class DisplayList;
}

namespace al {
class GpuMemAllocator;

class ModelDrawDisplayList {
public:
	ModelDrawDisplayList(const char*, GpuMemAllocator*, u32, u32);
	ModelDrawDisplayList();
	~ModelDrawDisplayList();
	void invalidate();
	agl::DisplayList* getDisplayList(s32);
	agl::DrawContext* prepDraw(agl::DrawContext*, const MeshDrawerTable*, ModelCtrl const* const*, s32, s32) const;
	void callDraw(agl::DrawContext*, const MeshDrawerTable*, ModelCtrl const* const*, s32, s32) const;

private:
	agl::DrawContext* mDrawCtx;
	agl::DisplayList* mDisplayLists;
	u32 unk1;
	u32 mDisplayListNum;
};

static_assert(sizeof(ModelDrawDisplayList) == 0x18);

}
