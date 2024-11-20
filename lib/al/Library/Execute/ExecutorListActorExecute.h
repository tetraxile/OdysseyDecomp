#pragma once

#include <basis/seadTypes.h>

#include "Library/Execute/ExecutorListBase.h"

namespace al {
class LiveActor;
class ExecutorActorExecuteBase;

class ExecutorListActorExecuteBase : public ExecutorListBase {
public:
    ExecutorListActorExecuteBase(const char* name, s32 size);
    virtual ~ExecutorListActorExecuteBase() override = default;
    void executeList() const override;
    bool isActive() const override;
    virtual ExecutorActorExecuteBase* createExecutor(const char* name) = 0;

    void registerActor(LiveActor*);
    void createList();

private:
    s32 mExecutorMaxNum = 0;
    s32 mExecutorNum = 0;
    ExecutorActorExecuteBase** mExecutors;
};

}
