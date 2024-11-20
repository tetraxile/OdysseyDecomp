#include "Library/Execute/ExecutorListActorExecute.h"

#include "Library/Base/StringUtil.h"
#include "Library/Execute/ExecutorActorExecuteBase.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {

ExecutorListActorExecuteBase::ExecutorListActorExecuteBase(const char* name, s32 size) : ExecutorListBase(name), mExecutorMaxNum(size) {
    mExecutors = new ExecutorActorExecuteBase*[size];
    for (s32 i = 0; i < mExecutorMaxNum; i++)
        mExecutors[i] = nullptr;
}

void ExecutorListActorExecuteBase::registerActor(LiveActor* actor) {
    ExecutorActorExecuteBase* executor;

    for (s32 i = 0; i < mExecutorNum; i++) {
        executor = mExecutors[i];
        if (isEqualString(executor->getName(), actor->getName())) {
            executor->registerActor(actor);
            return;
        }
    }

    executor = createExecutor(actor->getName());
    executor->registerActor(actor);
    mExecutors[mExecutorNum] = executor;
    mExecutorNum++;
}

void ExecutorListActorExecuteBase::createList() {
    for (s32 i = 0; i < mExecutorNum; i++)
        mExecutors[i]->createExecutorTable();
}

void ExecutorListActorExecuteBase::executeList() const {
    for (s32 i = 0; i < mExecutorNum; i++)
        mExecutors[i]->execute();
}

}
