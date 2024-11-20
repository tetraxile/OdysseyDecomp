#pragma once

#include <container/seadPtrArray.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>

#include "Library/HostIO/HioNode.h"
#include "Library/Message/IUseMessageSystem.h"
#include "Library/Scene/GameDataHolderBase.h"
#include "Library/Scene/ISceneObj.h"

#include "System/GameDataFile.h"

namespace al {
class PlacementId;
class PlacementInfo;
class LayoutInitInfo;
}

class WorldList;
class SaveDataAccessSequence;
class GameConfigData;
class TempSaveData;
class CapMessageBossData;
class TemporaryScenarioCameraHolder;
class MapDataHolder;
class UniqObjInfo;
class QuestInfoHolder;
class GameSequenceInfo;
class TimeBalloonSequenceInfo;
class AchievementInfoReader;
class AchievementHolder;
class Coin;
class ChangeStageInfo;

class GameDataHolder : public al::GameDataHolderBase, public al::ISceneObj, public al::HioNode, public al::IUseMessageSystem {
public:
    GameDataHolder(const al::MessageSystem* messageSystem);
    void setPlayingFileId(s32 fileId);
    void initializeData();
    GameDataHolder();
    void initializeDataCommon();
    void resetTempSaveData(bool isChangeWorld);
    void initializeDataId(s32 fileId);
    void readByamlData(s32 fileId, const char* fileName);
    s32 tryFindEmptyFileId() const;
    void createSaveDataAccessSequence(const al::LayoutInitInfo& initInfo);
    void createSaveDataAccessSequenceDevelop(const al::LayoutInitInfo& initInfo);
    bool isRequireSave() const;
    void setRequireSave();
    void setRequireSaveFalse();
    void setRequireSaveFrame();
    void updateRequireSaveFrame();
    bool isInvalidSaveForMoonGet() const;
    void invalidateSaveForMoonGet();
    void validateSaveForMoonGet();
    void setLanguage(const char* language);
    const char* getLanguage() const;
    void changeNextStage(const ChangeStageInfo* stageInfo, StageStart stageFlag);
    void resetLocationName();
    void changeNextStageWithDemoWorldWarp(const char* stageName);
    bool tryChangeNextStageWithWorldWarpHole(const char* stageName);
    void returnPrevStage();
    const char* getNextStageName() const;
    const char* getNextStageName(s32 fileId) const;
    GameDataFile* getGameDataFile(s32 fileId) const;
    const char* getNextPlayerStartId() const;
    const char* getCurrentStageName() const;
    const char* tryGetCurrentStageName() const;
    const char* getCurrentStageName(s32 fileId) const;
    void setCheckpointId(const al::PlacementId* checkpointId);
    const char* tryGetRestartPointIdString() const;
    void endStage();
    void startStage(const char* stageName, s32 nextScenarioNo);
    void onObjNoWriteSaveData(const al::PlacementId* obj);
    void offObjNoWriteSaveData(const al::PlacementId* obj);
    bool isOnObjNoWriteSaveData(const al::PlacementId* obj) const;
    void onObjNoWriteSaveDataResetMiniGame(const al::PlacementId* obj);
    void offObjNoWriteSaveDataResetMiniGame(const al::PlacementId* obj);
    bool isOnObjNoWriteSaveDataResetMiniGame(const al::PlacementId* obj) const;
    void onObjNoWriteSaveDataInSameScenario(const al::PlacementId* obj);
    bool isOnObjNoWriteSaveDataInSameScenario(const al::PlacementId* obj) const;
    void writeTempSaveDataToHash(const char* hashName, bool value);
    bool findValueFromTempSaveDataHash(const char* hashName);
    void resetMiniGameData();
    s32 getPlayingFileId() const;
    s32 getPlayingOrNextFileId() const;
    void requestSetPlayingFileId(s32 fileId);
    void receiveSetPlayingFileIdMsg();
    GameDataFile* findGameDataFile(const char* fileName) const;
    GameDataFile* findFileByName(const char* fileName) const;
    void resetScenarioStartCamera();
    void resetTempSaveDataInSameScenario();
    void readFromSaveDataBuffer(const char* fileName);
    bool tryReadByamlDataCommon(const u8* data);
    void readFromSaveDataBufferCommonFileOnlyLanguage();
    void writeToSaveDataBuffer(const char* fileName);
    void updateSaveInfoForDisp(const char* fileName);
    void updateSaveTimeForDisp(const char* fileName);
    s32 findUnlockShineNum(bool*, s32 worldId) const;
    s32 calcBeforePhaseWorldNumMax(s32) const;
    bool isFindKoopaNext(s32 worldId) const;
    bool isBossAttackedHomeNext(s32 worldId) const;
    void playScenarioStartCamera(s32 questNo);
    bool isPlayAlreadyScenarioStartCamera(s32 questNo) const;
    sead::PtrArrayImpl* getShopItemInfoList() const;
    bool checkNeedTreasureMessageStage(const char* stageName) const;
    bool tryFindLinkDestStageInfo(const char** destStageName, const char** destLabel, const char* srcStageName, const char* srcLabel) const;
    bool isShowHackTutorial(const char* hackName, const char* suffix) const;
    void setShowHackTutorial(const char* hackName, const char* suffix);
    bool isShowBindTutorial(const char* bindName) const;
    const char* getCoinCollectArchiveName(s32 worldId) const;
    const char* getCoinCollectEmptyArchiveName(s32 worldId) const;
    const char* getCoinCollect2DArchiveName(s32 worldId) const;
    const char* getCoinCollect2DEmptyArchiveName(s32 worldId) const;
    s32 getShineAnimFrame(s32 worldId) const;
    s32 getCoinCollectNumMax(s32 worldId) const;
    bool isInvalidOpenMapStage(const char* stageName, s32 scenarioNo) const;
    void setShowBindTutorial(const char* bindName);
    s32 tryCalcWorldWarpHoleSrcId(s32 destId) const;
    s32 calcWorldWarpHoleDestId(s32 srcId) const;
    s32 calcWorldWarpHoleIdFromWorldId(s32 worldId) const;
    s32 calcWorldIdFromWorldWarpHoleId(s32 worldWarpHoleId) const;
    void calcWorldWarpHoleLabelAndStageName(sead::BufferedSafeString*, sead::BufferedSafeString*, const char*, s32) const;
    void* findWorldWarpHoleInfo(s32, s32, const char*) const;
    bool checkIsOpenWorldWarpHoleInScenario(s32, s32) const;
    void setLocationName(const al::PlacementInfo* locationArea);
    bool isPrevLocation(const al::PlacementInfo* locationArea) const;
    void setCoinTransForDeadPlayer(const sead::PtrArray<Coin>& coins, s32 idx);
    sead::Vector3f* getCoinTransForDeadPlayer(s32 idx);
    void setSeparatePlay(bool isSeparatePlay);
    CapMessageBossData* getCapMessageBossData() const;
    s32 findUseScenarioNo(const char* stageName) const;
    const char* getSceneObjName() const override;
    ~GameDataHolder();
    al::MessageSystem* getMessageSystem() const override;

private:
    friend class GameDataFile;

    al::MessageSystem* mMessageSystem;
    GameDataFile** mFiles;
    GameDataFile* mPlayingFile;
    GameDataFile* mNextFile;
    s32 mPlayingFileId;
    SaveDataAccessSequence* mSaveDataAccessSequence;
    bool mIsRequireSave;
    u32 mRequireSaveFrame;
    bool mIsInvalidSaveForMoonGet;
    bool unk_changeStageRelated;
    bool unk1;
    sead::FixedSafeString<32> mLanguage;
    u64 mPlayTimeAcrossFiles;
    sead::Heap* field_90;
    u8* field_98;
    GameConfigData* mGameConfigData;
    TempSaveData* mMiniGameData;
    TempSaveData* field_b0;
    CapMessageBossData* mCapMessageBossData;
    u8 gap_C0[0x10];
    TemporaryScenarioCameraHolder* field_d0;
    bool* mIsPlayAlreadyScenarioStartCamera;
    sead::PtrArrayImpl mStageLockList;
    sead::PtrArrayImpl mShopItemList;
    sead::PtrArrayImpl mShopItemListE3;
    sead::PtrArrayImpl mItemCloth;
    sead::PtrArrayImpl mItemCap;
    sead::PtrArrayImpl mItemGift;
    sead::PtrArrayImpl mItemSticker;
    sead::PtrArrayImpl mHackObj;
    sead::PtrArrayImpl field_160;
    void* field_170;
    s32 field_178;
    AchievementInfoReader* mAchievementInfoReader;
    AchievementHolder* mAchievementHolder;
    WorldList* mWorldList;
    sead::PtrArrayImpl mChangeStageList;
    sead::PtrArrayImpl mExStageList;
    sead::PtrArrayImpl mInvalidOpenMapList;
    sead::PtrArrayImpl mShowHackTutorialList;
    bool* mIsShowBindTutorial;
    MapDataHolder* mMapDataHolder;
    s32 field_1e8;
    void** field_1f0;
    s32* mCoinCollectNumMax;
    s32* mWorldWarpHoleDestId;
    u64* field_208;
    s32 field_210;
    UniqObjInfo* mLocationName;
    bool field_220;
    u32 field_224;
    bool mIsValidCheckpointWarp;
    sead::Vector3f mStageMapPlayerPos;
    sead::Vector3f* mCoinTransForDeadPlayer;
    u32 field_240;
    bool field_244;
    bool mIsSeparatePlay;
    bool mIsPlayDemoLavaErupt;
    QuestInfoHolder* mQuestInfoHolder;
    bool field_250;
    GameSequenceInfo* mGameSequenceInfo;
    TimeBalloonSequenceInfo* mTimeBalloonSequenceInfo;
};

static_assert(sizeof(GameDataHolder) == 0x268);
