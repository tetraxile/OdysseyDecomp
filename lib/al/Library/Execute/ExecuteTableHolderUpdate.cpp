#include "Library/Execute/ExecuteTableHolderUpdate.h"

#include "Library/Execute/ExecuteOrder.h"
#include "Project/Execute/ExecuteFunction.h"

namespace al {

// ExecuteTableHolderUpdate::ExecuteTableHolderUpdate(){};
//
// ExecuteTableHolderUpdate::~ExecuteTableHolderUpdate(){};
//
// void ExecuteTableHolderUpdate::init(const char* name, const ExecuteSystemInitInfo& initInfo, const ExecuteOrder* orders, s32 orderCount) {
//     mName = name;
//     mListAllNumMax = orderCount;
//     mListsAll = new ExecutorListBase*[orderCount];
//
//     s32 actorNum = alExecutorFunction::calcUpdateListActorNumMax(orders, orderCount);
//     mListActorNumMax = actorNum;
//     mListsActor = new ExecutorListActorExecuteBase*[actorNum];
//
//     s32 layoutNum = alExecutorFunction::calcExecutorListNumMax(orders, orderCount, "LayoutUpdate");
//     mListLayoutNumMax = layoutNum;
//     mListsLayout = new ExecutorListLayoutUpdate*[layoutNum];
//
//     s32 userNum = alExecutorFunction::calcExecutorListNumMax(orders, orderCount, "Execute");
//     mListUserNumMax = userNum;
//     mListsUser = new ExecutorListIUseExecutorUpdate*[userNum];
//
//     s32 functorNum = alExecutorFunction::calcExecutorListNumMax(orders, orderCount, "Functor");
//     mListFunctorNumMax = functorNum;
//     mListsFunctor = new ExecutorListFunctor*[functorNum];
//
//     for (s32 i = 0; i < mListAllNumMax; i++) {
//         const ExecuteOrder& order = orders[i];
//         ExecutorListBase* list = nullptr;
//         if (alExecutorFunction::isListName(order, "ActorMovement")) {
//             list = new ExecutorListActorMovement(order->mListName, order->mListSize);
//             registerExecutorListActor(list);
//         }
//     }
// }
//
// ExecutorListActorExecuteBase* ExecuteTableHolderUpdate::registerExecutorListActor(ExecutorListActorExecuteBase* listActor) {
//     mListsActor[mListActorNum] = listActor;
//     mListActorNum++;
//     return listActor;
// }
//
// ExecutorListLayoutUpdate* ExecuteTableHolderUpdate::registerExecutorListLayout(ExecutorListLayoutUpdate* listLayout) {
//     mListsLayout[mListLayoutNum] = listLayout;
//     mListLayoutNum++;
//     return listLayout;
// }
//
// ExecutorListIUseExecutorUpdate* ExecuteTableHolderUpdate::registerExecutorListUser(ExecutorListIUseExecutorUpdate* listUser) {
//     mListsUser[mListUserNum] = listUser;
//     mListUserNum++;
//     return listUser;
// }
//
// ExecutorListFunctor* ExecuteTableHolderUpdate::registerExecutorListFunctor(ExecutorListFunctor* listFunctor) {
//     mListsFunctor[mListFunctorNum] = listFunctor;
//     mListFunctorNum++;
//     return listFunctor;
// }
//
// void ExecuteTableHolderUpdate::registerExecutorListAll(ExecutorListBase* list) {
//     mListsAll[mListAllNum] = list;
//     mListAllNum++;
// }

// void ExecuteTableHolderUpdate::tryRegisterActor(LiveActor* actor, const char* listName) {
//     bool result = false;
//     for (s32 i = 0; i < mListActorCount; i++) {
//         if (al::isEqualString(mListsActor[i], listName)) {
//             mListsActor[i]->registerActor(actor);
//             result = true;
//         }
//     }
// }

// void ExecuteTableHolderUpdate::tryRegisterLayout(LayoutActor* layout, const char* listName) {
//
// }
//
// void ExecuteTableHolderUpdate::tryRegisterUser(IUseExecutor* user, const char* listName) {
//
// }
//
// void ExecuteTableHolderUpdate::tryRegisterFunctor(const FunctorBase& functor, const char* listName) {
//     
// }
//
// void ExecuteTableHolderUpdate::createExecutorListTable() {
//
// }
//
// void ExecuteTableHolderUpdate::execute() const {
//
// }
//
// void ExecuteTableHolderUpdate::executeList(const char* listName) const {
//
// }

} // namespace al
