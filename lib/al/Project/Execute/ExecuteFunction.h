#pragma once

#include <basis/seadTypes.h>

namespace al {
class ExecuteDirector;
struct ExecuteOrder;
}

namespace alExecuteFunction {
void executeDraw(const al::ExecuteDirector* director, const char* tableName);
void executeDrawList(const al::ExecuteDirector* director, const char* tableName, const char* listName);
}

namespace alExecutorFunction {
bool isListName(const al::ExecuteOrder& order, const char* listName);
bool isUpdateListActor(const al::ExecuteOrder& order);
bool isDrawListActor(const al::ExecuteOrder& order);
bool isDrawListActorModel(const al::ExecuteOrder& order);
bool isDrawListLayout(const al::ExecuteOrder& order);

s32 calcExecutorListNumMax(const al::ExecuteOrder* orders, s32 orderCount, const char* listName);
s32 calcUpdateListActorNumMax(const al::ExecuteOrder* orders, s32 orderCount);
s32 calcDrawListActorNumMax(const al::ExecuteOrder* orders, s32 orderCount);
s32 calcDrawListActorModelNumMax(const al::ExecuteOrder* orders, s32 orderCount);
s32 calcDrawListLayoutNumMax(const al::ExecuteOrder* orders, s32 orderCount);
}
