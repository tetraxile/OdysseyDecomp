#include "System/GameDataHolderAccessor.h"

#include "Library/Scene/ISceneObj.h"
#include "Library/Scene/SceneObjHolder.h"
#include "Library/Scene/SceneUtil.h"

#include "System/GameDataHolder.h"

GameDataHolderAccessor::GameDataHolderAccessor(const al::IUseSceneObjHolder* holder) {
    mData = static_cast<GameDataHolder*>(al::getSceneObj(holder, 18));
}

GameDataHolderAccessor::GameDataHolderAccessor(const al::SceneObjHolder* holder) {
    mData = static_cast<GameDataHolder*>(holder->getObj(18));
}
