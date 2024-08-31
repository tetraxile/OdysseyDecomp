#pragma once

#include <basis/seadTypes.h>
#include <container/seadPtrArray.h>

#include "Library/Execute/ExecutorListBase.h"
#include "Library/Thread/FunctorV0M.h"

namespace al {

class ExecutorListFunctor : public ExecutorListBase {
public:
    ExecutorListFunctor(const char* name, s32 size);
    ~ExecutorListFunctor();
    void executeList() const override;
    bool isActive() const override;

    void registerFunctor(const FunctorBase& functor);

private:
    sead::PtrArray<FunctorBase> mFunctors;
};

static_assert(sizeof(ExecutorListFunctor) == 0x20);

}
