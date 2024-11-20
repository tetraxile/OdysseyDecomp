#include "Library/Execute/ExecutorListActorDraw.h"

#include "Library/Execute/ActorExecuteInfo.h"
#include "Library/Execute/ExecuteSystemInitInfo.h"
#include "Library/LiveActor/ActorSceneInfo.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/Model/ModelDrawerBase.h"
#include "Library/Model/ModelKeeper.h"
#include "Library/Base/StringUtil.h"

namespace al {

ExecutorListActorModelDrawBase::ExecutorListActorModelDrawBase(const char* name, s32 size, const ExecuteSystemInitInfo& initInfo) : ExecutorListBase(name), mDrawerMaxNum(size) {
    mDrawers = new ModelDrawerBase*[size];
    for (s32 i = 0; i < mDrawerMaxNum; i++)
        mDrawers[i] = nullptr;
    mDrawCtx = initInfo.mDrawCtx;
}

void ExecutorListActorModelDrawBase::registerActorModel(LiveActor* actor) {
    const char* modelName = actor->getModelKeeper()->getName();
    ModelCtrl* modelCtrl = actor->getModelKeeper()->getModelCtrl();
    for (s32 i = 0; i < mDrawerNum; i++) {
        ModelDrawerBase* drawer = mDrawers[i];
        if (drawer->getName(), modelName) {
            drawer->registerModel(modelCtrl);
            actor->getExecuteInfo()->addDrawer(drawer);
            return;
        }
    }

    ModelDrawerBase* drawer = createDrawer(modelName);
    drawer->setDrawInfo(mDrawCtx, actor->getSceneInfo()->mGraphicsSystemInfo, actor->getSceneInfo()->mModelDrawBufferCounter, actor->getModelKeeper());
    drawer->registerModel(modelCtrl);
    actor->getExecuteInfo()->addDrawer(drawer);
    mDrawers[mDrawerNum] = drawer;
    mDrawerNum++;
}

void ExecutorListActorModelDrawBase::createList() {
    for (s32 i = 0; i < mDrawerNum; i++)
        mDrawers[i]->createTable();
}

void ExecutorListActorModelDrawBase::executeList() const {
    if (mDrawerNum <= 0) return;

    isEqualString(getName(), "シルエット[プレイヤー]");
    isEqualString(getName(), "シルエット[乗り物]");

    for (s32 i = 0; i < mDrawerNum; i++)
        mDrawers[i]->draw();
}

bool ExecutorListActorModelDrawBase::isActive() const {
    return mDrawerNum > 0;
}

}
