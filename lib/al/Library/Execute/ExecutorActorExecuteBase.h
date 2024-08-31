#pragma once

#include "Library/HostIO/HioNode.h"

namespace al {
class LiveActor;

class ExecutorActorExecuteBase : public HioNode {
public:
    ExecutorActorExecuteBase(const char* name);

    virtual void execute() const = 0;

    void registerActor(LiveActor* actor);
    void createExecutorTable();
    void addActor(LiveActor* actor);
    void removeActor(LiveActor* actor);

    const char* getName() { return mName; }

private:
    const char* mName;
    s32 mRegisteredActorCount;
    s32 mActorCount;
    LiveActor** mActors;
};

}
