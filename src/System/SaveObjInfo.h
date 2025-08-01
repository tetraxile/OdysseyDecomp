#pragma once

namespace al {
struct ActorInitInfo;
class PlacementId;
}  // namespace al
class GameDataHolder;

class SaveObjInfo {
public:
    enum class SaveType { Write, NoWriteInSameWorld, NoWriteResetMinigame, NoWriteInSameScenario };

    static SaveObjInfo* createSaveObjInfoWriteSaveData(const al::ActorInitInfo& initInfo,
                                                       const al::PlacementId* id);
    static SaveObjInfo*
    createSaveObjInfoNoWriteSaveDataInSameWorld(const al::ActorInitInfo& initInfo,
                                                const al::PlacementId* id);
    static SaveObjInfo*
    createSaveObjInfoNoWriteSaveDataInSameWorldResetMiniGame(const al::ActorInitInfo& initInfo,
                                                             const al::PlacementId* id);
    static SaveObjInfo*
    createSaveObjInfoNoWriteSaveDataInSameScenario(const al::ActorInitInfo& initInfo,
                                                   const al::PlacementId* id);

    SaveObjInfo(const al::ActorInitInfo& initInfo, const al::PlacementId* placementId,
                SaveType saveType);

    void on();
    void off();
    bool isOn() const;
    void resetByPlacementId(al::PlacementId* id);
    bool checkIsOn() const;

private:
    const al::PlacementId* mPlacementId;
    bool mIsOn = false;
    SaveType mSaveType;
    GameDataHolder* mGameDataHolder = nullptr;
};
