#pragma once

#include <basis/seadTypes.h>

#include "Library/Execute/ExecutorListBase.h"

namespace agl {
class DrawContext;
}

namespace al {
struct ExecuteSystemInitInfo;
class LiveActor;
class ModelDrawerBase;

class ExecutorListActorModelDrawBase : public ExecutorListBase {
public:
    ExecutorListActorModelDrawBase(const char* name, s32 size, const ExecuteSystemInitInfo& initInfo);
    virtual ~ExecutorListActorModelDrawBase() override = default;
    void registerActorModel(LiveActor* actor);
    void createList();
    void executeList() const override;
    bool isActive() const override;
    virtual ModelDrawerBase* createDrawer(const char* name) const = 0;

private:
    s32 mDrawerMaxNum = 0;
    s32 mDrawerNum = 0;
    ModelDrawerBase** mDrawers = nullptr;
    agl::DrawContext* mDrawCtx = nullptr;
};

}
