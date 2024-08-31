#include "Library/Execute/ExecutorListFunctor.h"

namespace al {

ExecutorListFunctor::ExecutorListFunctor(const char* name, s32 size) : ExecutorListBase(name) {
    mFunctors.allocBuffer(size, nullptr);
}

void ExecutorListFunctor::registerFunctor(const FunctorBase& functor) {
    mFunctors.pushBack(functor.clone());
}

void ExecutorListFunctor::executeList() const {
    for (s32 i = 0; i < mFunctors.size(); i++) {
        const auto& functor = mFunctors[i];
        (*functor)();
    }
}

bool ExecutorListFunctor::isActive() const {
    return mFunctors.size() != 0;
}

ExecutorListFunctor::~ExecutorListFunctor() {}

}
