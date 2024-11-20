#pragma once

#include <basis/seadTypes.h>

#include "Library/HostIO/HioNode.h"

namespace agl {
class DrawContext;
}

namespace al {
class GraphicsSystemInfo;
struct ModelDrawBufferCounter;
class ModelKeeper;
class ModelDrawDisplayList;
class ModelCtrl;
class MeshDrawerTable;

class ModelDrawerBase : public HioNode {
public:
    ModelDrawerBase(const char* name);
    virtual ~ModelDrawerBase();
    virtual void createTable() = 0;
    virtual void draw() const = 0;
    virtual void registerModel(ModelCtrl* model);
    virtual void addModel(ModelCtrl* model);
    virtual void removeModel(ModelCtrl* model);
    virtual void updateModel(ModelCtrl* model);

    void setDrawInfo(agl::DrawContext* drawCtx, const GraphicsSystemInfo* gfxInfo, const ModelDrawBufferCounter* bufferCounter, const ModelKeeper* modelKeeper);
    bool addModelToTable(ModelCtrl* model);
    s32 getDrawBufferIndex() const;
    void createModelDrawDisplayList(s32);
    bool isDraw() const;

    const char* getName() const { return mName; }

private:
    const char* mName = nullptr;
    agl::DrawContext* mDrawCtx = nullptr;
    const ModelKeeper* mModelKeeper = nullptr;
    const GraphicsSystemInfo* mGraphicsSystemInfo = nullptr;
    const ModelDrawBufferCounter* mBufferCounter = nullptr;
    ModelDrawDisplayList* mDrawDisplayList = nullptr;
    s32 mModelNum = 0;
    s32 mModelMaxNum = 0;
    ModelCtrl** mModels = nullptr;
    MeshDrawerTable* mMeshDrawerTable = nullptr;
};

static_assert(sizeof(ModelDrawerBase) == 0x50);

}  // namespace al
