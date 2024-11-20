#pragma once

#include "System/GameDataHolderWriter.h"

namespace al {
class IUseSceneObjHolder;
class SceneObjHolder;
class LiveActor;
}  // namespace al

class GameDataHolder;

class GameDataHolderAccessor : public GameDataHolderWriter {
public:
    GameDataHolderAccessor(const al::IUseSceneObjHolder* holder);
    GameDataHolderAccessor(const al::SceneObjHolder* holder);

    GameDataHolderAccessor(GameDataHolder* data) : GameDataHolderWriter(data) {}
};

namespace rs {
bool isInvalidChangeStage(const al::LiveActor*);
}
