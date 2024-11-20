#include "System/GameDataHolder.h"

#include "Scene/QuestInfoHolder.h"
#include "System/GameDataFile.h"

namespace al {
class IUseSceneObjHolder;
}

GameDataHolder::GameDataHolder(const al::MessageSystem* messageSystem) {

}

void GameDataHolder::setPlayingFileId(s32 fileId) {
    mPlayingFile = mFiles[fileId];
    resetTempSaveData(false);
    if (fileId != -1)
        mPlayingFileId = fileId;
}

void GameDataHolder::initializeData() {
    for (s32 i = 0; i < 5; i++)
        mFiles[i]->initializeData();

    initializeDataCommon();
}

GameDataHolder::GameDataHolder() {

}

void GameDataHolder::initializeDataCommon() {

}

void GameDataHolder::resetTempSaveData(bool isChangeWorld) {
    if (isChangeWorld)


    for (s32 i = 0; i < 5; i++)
        mFiles[i]->resetTempData();

    for (s32 i = 0; i < 0x10; i++)
        mIsPlayAlreadyScenarioStartCamera[i] = false;

    mQuestInfoHolder->clearAll();

    field_250 = false;
}

void GameDataHolder::initializeDataId(s32 fileId) {

}

void GameDataHolder::readByamlData(s32 fileId, const char* fileName) {

}

s32 GameDataHolder::tryFindEmptyFileId() const {

}

void GameDataHolder::createSaveDataAccessSequence(const al::LayoutInitInfo& initInfo) {

}

void GameDataHolder::createSaveDataAccessSequenceDevelop(const al::LayoutInitInfo& initInfo) {

}

bool GameDataHolder::isRequireSave() const {

}

void GameDataHolder::setRequireSave() {

}

void GameDataHolder::setRequireSaveFalse() {

}

void GameDataHolder::setRequireSaveFrame() {

}

void GameDataHolder::updateRequireSaveFrame() {

}

bool GameDataHolder::isInvalidSaveForMoonGet() const {

}

void GameDataHolder::invalidateSaveForMoonGet() {

}

void GameDataHolder::validateSaveForMoonGet() {

}

void GameDataHolder::setLanguage(const char* language) {

}

const char* GameDataHolder::getLanguage() const {
    return mLanguage.cstr();
}

void GameDataHolder::changeNextStage(const ChangeStageInfo* stageInfo, StageStart stageStart) {

}

void GameDataHolder::resetLocationName() {

}

void GameDataHolder::changeNextStageWithDemoWorldWarp(const char* stageName) {

}

bool GameDataHolder::tryChangeNextStageWithWorldWarpHole(const char* stageName) {

}

void GameDataHolder::returnPrevStage() {

}

const char* GameDataHolder::getNextStageName() const {

}

const char* GameDataHolder::getNextStageName(s32 fileId) const {

}

GameDataFile* GameDataHolder::getGameDataFile(s32 fileId) const {
    return mFiles[fileId];
}

const char* GameDataHolder::getNextPlayerStartId() const {

}

const char* GameDataHolder::getCurrentStageName() const {

}

const char* GameDataHolder::tryGetCurrentStageName() const {

}

const char* GameDataHolder::getCurrentStageName(s32 fileId) const {

}

void GameDataHolder::setCheckpointId(const al::PlacementId* checkpointId) {

}

const char* GameDataHolder::tryGetRestartPointIdString() const {

}

void GameDataHolder::endStage() {

}

void GameDataHolder::startStage(const char* stageName, s32 nextScenarioNo) {

}

void GameDataHolder::onObjNoWriteSaveData(const al::PlacementId* obj) {

}

void GameDataHolder::offObjNoWriteSaveData(const al::PlacementId* obj) {

}

bool GameDataHolder::isOnObjNoWriteSaveData(const al::PlacementId* obj) const {

}

void GameDataHolder::onObjNoWriteSaveDataResetMiniGame(const al::PlacementId* obj) {

}

void GameDataHolder::offObjNoWriteSaveDataResetMiniGame(const al::PlacementId* obj) {

}

bool GameDataHolder::isOnObjNoWriteSaveDataResetMiniGame(const al::PlacementId* obj) const {

}

void GameDataHolder::onObjNoWriteSaveDataInSameScenario(const al::PlacementId* obj) {

}

bool GameDataHolder::isOnObjNoWriteSaveDataInSameScenario(const al::PlacementId* obj) const {

}

void GameDataHolder::writeTempSaveDataToHash(const char* hashName, bool value) {

}

bool GameDataHolder::findValueFromTempSaveDataHash(const char* hashName) {

}

void GameDataHolder::resetMiniGameData() {

}

s32 GameDataHolder::getPlayingFileId() const {
    for (s32 i = 0; i < 5; i++)
        if (mPlayingFile == mFiles[i])
            return i;

    return -1;
}

s32 GameDataHolder::getPlayingOrNextFileId() const {

}

void GameDataHolder::requestSetPlayingFileId(s32 fileId) {

}

void GameDataHolder::receiveSetPlayingFileIdMsg() {

}

GameDataFile* GameDataHolder::findGameDataFile(const char* fileName) const {

}

GameDataFile* GameDataHolder::findFileByName(const char* fileName) const {

}

void GameDataHolder::resetScenarioStartCamera() {

}

void GameDataHolder::resetTempSaveDataInSameScenario() {

}

void GameDataHolder::readFromSaveDataBuffer(const char* fileName) {

}

bool GameDataHolder::tryReadByamlDataCommon(const u8* data) {

}

void GameDataHolder::readFromSaveDataBufferCommonFileOnlyLanguage() {

}

void GameDataHolder::writeToSaveDataBuffer(const char* fileName) {

}

void GameDataHolder::updateSaveInfoForDisp(const char* fileName) {

}

void GameDataHolder::updateSaveTimeForDisp(const char* fileName) {

}

s32 GameDataHolder::findUnlockShineNum(bool*, s32 worldId) const {

}

s32 GameDataHolder::calcBeforePhaseWorldNumMax(s32) const {

}

bool GameDataHolder::isFindKoopaNext(s32 worldId) const {

}

bool GameDataHolder::isBossAttackedHomeNext(s32 worldId) const {

}

void GameDataHolder::playScenarioStartCamera(s32 questNo) {

}

bool GameDataHolder::isPlayAlreadyScenarioStartCamera(s32 questNo) const {

}

sead::PtrArrayImpl* GameDataHolder::getShopItemInfoList() const {

}

bool GameDataHolder::checkNeedTreasureMessageStage(const char* stageName) const {

}

bool GameDataHolder::tryFindLinkDestStageInfo(const char** destStageName, const char** destLabel, const char* srcStageName, const char* srcLabel) const {

}

bool GameDataHolder::isShowHackTutorial(const char* hackName, const char* suffix) const {

}

void GameDataHolder::setShowHackTutorial(const char* hackName, const char* suffix) {

}

bool GameDataHolder::isShowBindTutorial(const char* bindName) const {

}

const char* GameDataHolder::getCoinCollectArchiveName(s32 worldId) const {

}

const char* GameDataHolder::getCoinCollectEmptyArchiveName(s32 worldId) const {

}

const char* GameDataHolder::getCoinCollect2DArchiveName(s32 worldId) const {

}

const char* GameDataHolder::getCoinCollect2DEmptyArchiveName(s32 worldId) const {

}

s32 GameDataHolder::getShineAnimFrame(s32 worldId) const {

}

s32 GameDataHolder::getCoinCollectNumMax(s32 worldId) const {

}

bool GameDataHolder::isInvalidOpenMapStage(const char* stageName, s32 scenarioNo) const {

}

void GameDataHolder::setShowBindTutorial(const char* bindName) {

}

s32 GameDataHolder::tryCalcWorldWarpHoleSrcId(s32 destId) const {

}

s32 GameDataHolder::calcWorldWarpHoleDestId(s32 srcId) const {

}

s32 GameDataHolder::calcWorldWarpHoleIdFromWorldId(s32 worldId) const {

}

s32 GameDataHolder::calcWorldIdFromWorldWarpHoleId(s32 worldWarpHoleId) const {

}

void GameDataHolder::calcWorldWarpHoleLabelAndStageName(sead::BufferedSafeString*, sead::BufferedSafeString*, const char*, s32) const {

}

void* GameDataHolder::findWorldWarpHoleInfo(s32, s32, const char*) const {

}

bool GameDataHolder::checkIsOpenWorldWarpHoleInScenario(s32, s32) const {

}

void GameDataHolder::setLocationName(const al::PlacementInfo* locationArea) {

}

bool GameDataHolder::isPrevLocation(const al::PlacementInfo* locationArea) const {

}

void GameDataHolder::setCoinTransForDeadPlayer(const sead::PtrArray<Coin>& coins, s32 idx) {

}

sead::Vector3f* GameDataHolder::getCoinTransForDeadPlayer(s32 idx) {

}

void GameDataHolder::setSeparatePlay(bool isSeparatePlay) {
    // mIsSeparatePlay = isSeparatePlay;
    // rs::trySavePrepoSeparatePlayMode(isSeparatePlay, mPlayingFile->getPlayTimeTotal(), mPlayingFile->mSaveDataIdForPrepo, mPlayTimeAcrossFiles);
}

CapMessageBossData* GameDataHolder::getCapMessageBossData() const {
    return mCapMessageBossData;
}

s32 GameDataHolder::findUseScenarioNo(const char* stageName) const {

}

const char* GameDataHolder::getSceneObjName() const {
    return "ゲームデータ保持";
}

GameDataHolder::~GameDataHolder() {

}

al::MessageSystem* GameDataHolder::getMessageSystem() const {
    return mMessageSystem;
}
