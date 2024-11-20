#include "System/GameDataFunction.h"

#include <Library/Scene/SceneUtil.h>

#include "Scene/SceneObjFactory.h"

GameDataHolder* GameDataFunction::getGameDataHolder(const al::IUseSceneObjHolder* holder) {
    return static_cast<GameDataHolder*>(al::getSceneObj(holder, SceneObjID_GameDataHolder));
}

GameDataHolder* GameDataFunction::getGameDataHolder(const al::SceneObjHolder* holder) {
    return holder->getObj(SceneObjID_GameDataHolder);
}

GameDataHolder* GameDataFunction::getGameDataHolder(al::GameDataHolderBase* holder) {}

GameDataFile* GameDataFunction::getGameDataFile(GameDataHolderWriter writer) {}

void GameDataFunction::setPlayingFileId(GameDataHolderWriter writer, s32 fileId) {}

void GameDataFunction::initializeData(GameDataHolderWriter writer, s32 fileId) {}

bool GameDataFunction::isPlayDemoOpening(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isGameClear(GameDataHolderAccessor accessor) {}

void GameDataFunction::setRequireSave(GameDataHolderWriter writer) {}

void GameDataFunction::setRequireSaveFrame(GameDataHolderWriter writer) {}

u64 GameDataFunction::getPlayTimeTotal(GameDataHolderAccessor accessor) {}

u64 GameDataFunction::getPlayTimeAcrossFile(GameDataHolderAccessor accessor) {}

s64 GameDataFunction::getSaveDataIdForPrepo(GameDataHolderAccessor accessor) {}

void GameDataFunction::startDemoStage(GameDataHolderWriter writer, const char* stageName) {}

bool GameDataFunction::tryChangeNextStage(GameDataHolderWriter writer,
                                          const ChangeStageInfo* stageInfo) {}

bool GameDataFunction::tryChangeNextStageWithStartRaceFlag(GameDataHolderWriter writer,
                                                           const ChangeStageInfo* stageInfo) {}

bool GameDataFunction::tryChangeNextStageWithStartRaceYukimaru(GameDataHolderWriter writer,
                                                               const ChangeStageInfo* stageInfo) {}

bool GameDataFunction::tryChangeNextStageWithDemoWorldWarp(GameDataHolderWriter writer,
                                                           const char* stageName) {}

bool GameDataFunction::tryChangeNextStageWithWorldWarpHole(GameDataHolderWriter writer,
                                                           const char* stageName) {}

void GameDataFunction::changeNextStageWithStartTimeBalloon(GameDataHolderWriter writer,
                                                           s32 scenarioNo) {}

const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor accessor) {}

void GameDataFunction::changeNextStageWithEndTimeBalloon(GameDataHolderWriter writer) {}

void GameDataFunction::changeNextStageWithCloset(GameDataHolderWriter writer) {}

void GameDataFunction::findAreaAndChangeNextStage(GameDataHolderWriter writer,
                                                  const al::LiveActor* actor,
                                                  const sead::Vector3f* actorTrans) {}

void GameDataFunction::returnPrevStage(GameDataHolderWriter writer) {}

bool GameDataFunction::isTimeBalloonSequence(GameDataHolderAccessor accessor) {}

const char* GameDataFunction::getNextStageName(GameDataHolderAccessor accessor) {}

const char* GameDataFunction::getCurrentStageName(GameDataHolderAccessor accessor, s32 fileId) {}

bool GameDataFunction::isSeaOfTreeStage(GameDataHolderAccessor accessor) {}

const char* GameDataFunction::getNextStageName(GameDataHolderAccessor accessor, s32 fileId) {}

s32 GameDataFunction::calcNextScenarioNo(GameDataHolderAccessor accessor) {}

void GameDataFunction::restartStage(GameDataHolderWriter writer) {}

void GameDataFunction::missAndRestartStage(GameDataHolderWriter writer) {}

bool GameDataFunction::isMissEndPrevStageForInit(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isMissEndPrevStageForSceneDead(GameDataHolderAccessor accessor) {}

void GameDataFunction::reenterStage(GameDataHolderWriter writer) {}

s32 GameDataFunction::getNextWorldId(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getPrevWorldId(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getWorldNumForNewReleaseShop(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isAlreadyGoWorld(GameDataHolderAccessor accessor, s32 worldId) {}

const char* GameDataFunction::getWorldDevelopName(GameDataHolderAccessor accessor, s32 worldId) {}

s32 GameDataFunction::getWorldIdForNewReleaseShop(GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::isForwardWorldWarpDemo(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getWorldNum(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isFirstTimeNextWorld(GameDataHolderAccessor accessor) {}

bool GameDataFunction::checkIsNewWorldInAlreadyGoWorld(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getCurrentWorldIdNoDevelop(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getScenarioNo(const al::LiveActor* actor) {}

s32 GameDataFunction::getScenarioNo(const al::LayoutActor* layout) {}

s32 GameDataFunction::getScenarioNoPlacement(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isEqualScenario(const RiseMapPartsHolder*, s32 scenarioNo) {}

s32 GameDataFunction::getMainQuestMin(const al::LiveActor* actor) {}

s32 GameDataFunction::getCurrentWorldId(GameDataHolderAccessor accessor) {}

void GameDataFunction::clearStartId(GameDataHolderWriter writer) {}

void GameDataFunction::setCheckpointId(GameDataHolderWriter writer,
                                       const al::PlacementId* checkpointFlag) {}

void GameDataFunction::setRestartPointId(GameDataHolderWriter writer,
                                         const al::PlacementId* playerRestartInfo) {}

const char* GameDataFunction::tryGetRestartPointIdString(GameDataHolderAccessor accessor) {}

const char* GameDataFunction::tryGetPlayerStartId(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPlayerStartObj(const al::LiveActor* actor,
                                        const al::ActorInitInfo& initInfo) {}

bool GameDataFunction::isPlayerStartObj(const al::LiveActor* actor,
                                        const al::PlacementInfo& placementInfo) {}

bool GameDataFunction::isPlayerStartObj(const al::LiveActor* actor, const char* playerStartId) {}

bool GameDataFunction::isPlayerStartLinkedObj(const al::LiveActor* actor,
                                              const al::ActorInitInfo& initInfo,
                                              const char* linkName) {}

void GameDataFunction::setStartShine(const al::LiveActor* actor, const ShineInfo* shineInfo) {}

s32 GameDataFunction::getStartShineNextIndex(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isAlreadyShowExplainCheckpointFlag(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isEnableShowExplainCheckpointFlag(GameDataHolderAccessor accessor) {}

void GameDataFunction::showExplainCheckpointFlag(GameDataHolderAccessor accessor) {}

void GameDataFunction::getLifeMaxUpItem(const al::LiveActor* actor) {}

s32 GameDataFunction::getPlayerHitPoint(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getPlayerHitPointMaxCurrent(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getPlayerHitPointMaxNormal(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPlayerHitPointMax(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPlayerHitPointMaxWithItem(GameDataHolderAccessor accessor) {}

void GameDataFunction::recoveryPlayer(const al::LiveActor* actor) {}

void GameDataFunction::recoveryPlayerForDebug(const al::LiveActor* actor) {}

void GameDataFunction::recoveryPlayerMax(const al::LiveActor* actor) {}

void GameDataFunction::recoveryPlayerForSystem(const GameDataHolder* holder) {}

void GameDataFunction::recoveryPlayerMaxForSystem(const GameDataHolder* holder) {}

void GameDataFunction::initPlayerHitPointForSystem(const GameDataHolder* holder) {}

void GameDataFunction::damagePlayer(GameDataHolderWriter writer) {}

void GameDataFunction::killPlayer(GameDataHolderWriter writer) {}

bool GameDataFunction::isPlayerLifeZero(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isGotShine(GameDataHolderAccessor accessor, const ShineInfo* shineInfo) {}

bool GameDataFunction::isGotShine(GameDataHolderAccessor accessor, const al::PlacementId* shine) {}

bool GameDataFunction::isGotShine(GameDataHolderAccessor accessor, const char* stageName,
                                  const char* objId) {}

bool GameDataFunction::isGotShine(GameDataHolderAccessor accessor, s32 shineIdx) {}

bool GameDataFunction::isGotShine(const Shine* shineActor) {}

void GameDataFunction::setGotShine(GameDataHolderWriter writer, const ShineInfo* shineInfo) {}

s32 GameDataFunction::getGotShineNum(GameDataHolderAccessor accessor, s32 fileId) {}

ShineInfo* GameDataFunction::getLatestGetShineInfo(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getCurrentShineNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getTotalShineNum(GameDataHolderAccessor accessor, s32 fileId) {}

s32 GameDataFunction::getTotalShopShineNum(GameDataHolderAccessor accessor, s32 fileId) {}

bool GameDataFunction::tryGetNextMainScenarioLabel(sead::BufferedSafeStringBase<char>* scenarioName,
                                                   sead::BufferedSafeStringBase<char>* stageName,
                                                   const al::IUseSceneObjHolder* holder) {}

s32 GameDataFunction::getMainScenarioNumMax(GameDataHolderAccessor accessor) {}

void GameDataFunction::setMainScenarioNo(GameDataHolderWriter writer, s32 worldId) {}

bool GameDataFunction::tryGetNextMainScenarioPos(sead::Vector3f*, GameDataHolderAccessor accessor) {

}

bool GameDataFunction::isPlayScenarioCamera(GameDataHolderAccessor accessor,
                                            const QuestInfo* questInfo) {}

bool GameDataFunction::isPlayAlreadyScenarioStartCamera(GameDataHolderAccessor accessor, s32) {}

bool GameDataFunction::isEnterStageFirst(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isNextMainShine(GameDataHolderAccessor accessor, s32 shineIdx) {}

bool GameDataFunction::isMainShine(GameDataHolderAccessor accessor, s32 shineIdx) {}

bool GameDataFunction::isLatestGetMainShine(GameDataHolderAccessor accessor,
                                            const ShineInfo* shineInfo) {}

s32 GameDataFunction::tryFindLinkedShineIndex(const al::LiveActor* actor,
                                              const al::ActorInitInfo& initInfo) {}

s32 GameDataFunction::tryFindLinkedShineIndex(const al::LiveActor* actor,
                                              const al::ActorInitInfo& initInfo, s32 linkIdx) {}

s32 GameDataFunction::tryFindLinkedShineIndexByLinkName(const al::LiveActor* actor,
                                                        const al::ActorInitInfo& initInfo,
                                                        const char* linkName) {}

s32 GameDataFunction::calcLinkedShineNum(const al::LiveActor* actor,
                                         const al::ActorInitInfo& initInfo) {}

s32 GameDataFunction::tryFindShineIndex(const al::LiveActor* actor,
                                        const al::ActorInitInfo& initInfo) {}

s32 GameDataFunction::tryFindShineIndex(const al::LiveActor* actor, const char* stageName,
                                        const char* objId) {}

s32 GameDataFunction::tryFindShineUniqueId(const al::Scene* scene, const ShineInfo* shineInfo) {}

void GameDataFunction::disableHintByShineIndex(const al::LiveActor* actor, s32 shineIdx) {}

void GameDataFunction::enableHintByShineIndex(const al::LiveActor* actor, s32 shineIdx) {}

bool GameDataFunction::calcIsGetMainShineAll(const al::IUseSceneObjHolder* holder) {}

bool GameDataFunction::calcIsGetShineAllInWorld(GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::calcIsGetShineAllInAllWorld(GameDataHolderAccessor accessor) {}

bool GameDataFunction::tryFindAndInitShineInfoByOptionalId(ShineInfo* shineInfo,
                                                           GameDataHolderAccessor accessor,
                                                           const char* optionalId) {}

bool GameDataFunction::isGotLinkedShineBeforeInitActor(const al::ActorInitInfo& actorInitInfo,
                                                       const char* linkName) {}

bool GameDataFunction::checkIsComplete(const al::IUseSceneObjHolder* holder, s32 fileId) {}

bool GameDataFunction::isExistInHackDictionary(GameDataHolderAccessor accessor,
                                               const char* hackName, s32 fileId) {}

s32 GameDataFunction::getCollectedBgmNum(GameDataHolderAccessor accessor, s32 fileId) {}

s32 GameDataFunction::getCollectedBgmMaxNum(GameDataHolderWriter writer) {}

bool GameDataFunction::isEnableOpenMoonRock(const al::LiveActor* actor) {}

void GameDataFunction::openMoonRock(const al::LiveActor* actor, const al::PlacementId* moonRock) {}

bool GameDataFunction::isOpenMoonRock(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isEnableShowDemoOpenMoonRockFirst(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isEnableShowDemoOpenMoonRockWorld(GameDataHolderAccessor accessor) {}

void GameDataFunction::showDemoOpenMoonRockFirst(GameDataHolderAccessor accessor) {}

void GameDataFunction::showDemoOpenMoonRockWorld(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::calcMoonRockTalkMessageIndex(GameDataHolderAccessor accessor) {}

void GameDataFunction::addMoonRockTalkMessageIndex(GameDataHolderWriter writer) {}

bool GameDataFunction::isAppearedMoonRockTalkMessage(GameDataHolderAccessor accessor) {}

void GameDataFunction::addPayShine(GameDataHolderWriter writer, s32 count) {}

void GameDataFunction::addPayShineCurrentAll(GameDataHolderWriter writer) {}

s32 GameDataFunction::getPayShineNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getPayShineNum(GameDataHolderAccessor accessor, s32 worldId) {}

s32 GameDataFunction::getTotalPayShineNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getTotalPayShineNumClamp(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPayShineAllInAllWorld(GameDataHolderAccessor accessor) {}

void GameDataFunction::addKey(GameDataHolderWriter writer, s32 count) {}

s32 GameDataFunction::getKeyNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getCurrentKeyNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getOpenDoorLockNum(GameDataHolderAccessor accessor) {}

void GameDataFunction::openDoorLock(GameDataHolderWriter writer, const al::PlacementId* doorLock) {}

bool GameDataFunction::isOpenDoorLock(GameDataHolderAccessor accessor,
                                      const al::PlacementId* doorLock) {}

void GameDataFunction::setObjStarted(GameDataHolder* holder, const al::PlacementId* obj) {}

bool GameDataFunction::isObjStarted(const GameDataHolder* holder, const al::PlacementId* obj) {}

bool GameDataFunction::isObjStarted(GameDataHolderAccessor accessor, const char* stageName,
                                    const char* objId) {}

void GameDataFunction::saveObjS32(GameDataHolderWriter writer, const al::PlacementId* obj,
                                  s32 value) {}

bool GameDataFunction::tryFindSaveObjS32Value(s32* outValue, GameDataHolderAccessor accessor,
                                              const al::PlacementId* obj) {}

void GameDataFunction::onObjNoWriteSaveData(GameDataHolderWriter writer,
                                            const al::PlacementId* obj) {}

void GameDataFunction::offObjNoWriteSaveData(GameDataHolderWriter writer,
                                             const al::PlacementId* obj) {}

bool GameDataFunction::isOnObjNoWriteSaveData(GameDataHolderAccessor accessor,
                                              const al::PlacementId* obj) {}

void GameDataFunction::onObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter writer,
                                                         const al::PlacementId* obj) {}

void GameDataFunction::offObjNoWriteSaveDataResetMiniGame(GameDataHolderWriter writer,
                                                          const al::PlacementId* obj) {}

bool GameDataFunction::isOnObjNoWriteSaveDataResetMiniGame(GameDataHolderAccessor accessor,
                                                           const al::PlacementId* obj) {}

void GameDataFunction::onObjNoWriteSaveDataInSameScenario(GameDataHolder* holder,
                                                          const al::PlacementId* obj) {}

bool GameDataFunction::isOnObjNoWriteSaveDataInSameScenario(const GameDataHolder* holder,
                                                            const al::PlacementId* obj) {}

void GameDataFunction::setSessionEventProgress(GameDataHolderWriter writer,
                                               const SessionEventProgress& progress) {}

SessionEventProgress GameDataFunction::getSessionEventProgress(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPayCoinToSphinx(const al::LiveActor* actor) {}

void GameDataFunction::payCoinToSphinx(const al::LiveActor* actor) {}

bool GameDataFunction::isRemovedCapByJango(const al::LiveActor* actor) {}

bool GameDataFunction::isMainStage(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isGetCapFromJango(const al::LiveActor* actor) {}

void GameDataFunction::removeCapByJango(const al::LiveActor* actor) {}

void GameDataFunction::getCapFromJango(const al::LiveActor* actor) {}

void GameDataFunction::addJangoCount(const al::LiveActor* actor) {}

s32 GameDataFunction::getJangoCount(const al::LiveActor* actor) {}

bool GameDataFunction::isFirstWorldTravelingStatus(const WorldTravelingNpc* actor) {}

void GameDataFunction::saveWorldTravelingStatus(const WorldTravelingNpc* actor,
                                                const char* status) {}

const char* GameDataFunction::getWorldTravelingStatus(const WorldTravelingNpc* actor) {}

bool GameDataFunction::isRaceStart(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceStartFlag(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceStartYukimaru(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceStartYukimaruTutorial(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceWin(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceWin(GameDataHolderAccessor accessor, s32) {}

bool GameDataFunction::isRaceResultSecond(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceResultThird(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceLose(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isRaceCancel(GameDataHolderAccessor accessor) {}

void GameDataFunction::winRace(GameDataHolderWriter writer) {}

void GameDataFunction::endRaceResultSecond(GameDataHolderWriter writer) {}

void GameDataFunction::endRaceResultThird(GameDataHolderWriter writer) {}

void GameDataFunction::loseRace(GameDataHolderWriter writer) {}

s32 GameDataFunction::getRaceRivalLevel(const al::LiveActor* actor) {}

s32 GameDataFunction::getRaceRivalLevel(const al::Scene* scene) {}

void GameDataFunction::setRaceRivalLevel(const al::LiveActor* actor, s32 level) {}

void GameDataFunction::setLastRaceRanking(GameDataHolderAccessor accessor, s32 ranking) {}

s32 GameDataFunction::getLastRaceRanking(GameDataHolderWriter writer) {}

void GameDataFunction::incrementRaceLoseCount(const al::Scene* scene, s32 level) {}

s32 GameDataFunction::getRaceLoseCount(const al::LiveActor*, s32 level) {}

void GameDataFunction::addCoinCollect(GameDataHolderWriter writer,
                                      const al::PlacementId* coinCollect) {}

void GameDataFunction::useCoinCollect(GameDataHolderWriter writer, s32 count) {}

bool GameDataFunction::isGotCoinCollect(GameDataHolderAccessor accessor,
                                        const al::ActorInitInfo& coinCollect) {}

s32 GameDataFunction::getCoinCollectNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getCoinCollectGotNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getCoinCollectGotNum(GameDataHolderAccessor accessor, s32 worldId) {}

s32 GameDataFunction::getCoinCollectNumMax(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getCoinCollectNumMax(GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::tryFindExistCoinCollectStagePosExcludeHomeStageInCurrentWorld(
    sead::Vector3f* pos, const char**, GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getWorldScenarioNo(GameDataHolderAccessor accessor, s32 worldId) {}

void GameDataFunction::addCoin(GameDataHolderWriter writer, s32 count) {}

void GameDataFunction::subCoin(GameDataHolderWriter writer, s32 count) {}

s32 GameDataFunction::getCoinNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getTotalCoinNum(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isAppearCourseName(GameDataHolderAccessor accessor) {}

void GameDataFunction::setStageHakoniwa(GameDataHolderWriter writer) {}

bool GameDataFunction::isEnableCheckpointWarp(GameDataHolderAccessor accessor) {}

void GameDataFunction::validateCheckpointWarp(GameDataHolderWriter writer) {}

void GameDataFunction::invalidateCheckpointWarp(GameDataHolderWriter writer) {}

s32 GameDataFunction::getCheckpointNumMaxInWorld(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getCheckpointTransInWorld(GameDataHolderAccessor accessor,
                                                            s32 checkpointIdx) {}

const char* GameDataFunction::getCheckpointObjIdInWorld(GameDataHolderAccessor accessor,
                                                        s32 checkpointIdx) {}

sead::Vector3f* GameDataFunction::getCheckpointTransInWorld(GameDataHolderAccessor accessor,
                                                            const char* objId) {}

bool GameDataFunction::isGotCheckpointInWorld(GameDataHolderAccessor accessor, s32 checkpointIdx) {}

bool GameDataFunction::isGotCheckpoint(GameDataHolderAccessor accessor,
                                       al::PlacementId* checkpoint) {}

s32 GameDataFunction::calcGotCheckpointNumInWorld(GameDataHolderAccessor accessor) {}

void GameDataFunction::changeNextSceneByGotCheckpoint(GameDataHolderWriter writer,
                                                      s32 checkpointIdx) {}

void GameDataFunction::changeNextSceneByHome(GameDataHolderWriter writer) {}

bool GameDataFunction::isWarpCheckpoint(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getCheckpointWarpObjId(GameDataHolderAccessor accessor) {}

void GameDataFunction::registerCheckpointTrans(GameDataHolderWriter writer,
                                               const al::PlacementId* checkpoint,
                                               const sead::Vector3f& trans) {}

bool GameDataFunction::isEnableUnlockHint(GameDataHolderAccessor accessor) {}

void GameDataFunction::unlockHint(GameDataHolderWriter writer) {}

void GameDataFunction::unlockHintAmiibo(GameDataHolderWriter writer) {}

s32 GameDataFunction::calcHintNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::calcRestHintNum(GameDataHolderAccessor accessor) {}

bool GameDataFunction::checkExistHint(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getHintNumMax(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::calcHintTrans(GameDataHolderAccessor accessor, s32 hintIdx) {}

sead::Vector3f* GameDataFunction::getLatestHintTrans(GameDataHolderAccessor accessor) {}

bool GameDataFunction::checkLatestHintSeaOfTree(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::calcHintMoonRockNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getHintMoonRockNumMax(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::calcHintMoonRockTrans(GameDataHolderAccessor accessor,
                                                        s32 hintIdx) {}

void GameDataFunction::initializeHintList(GameDataHolderWriter writer) {}

sead::Vector3f* GameDataFunction::calcHintTransMostEasy(GameDataHolderAccessor accessor) {}

bool GameDataFunction::calcHintTransMostNear(sead::Vector3f* trans, GameDataHolderAccessor accessor,
                                             const sead::Vector3f& pos) {}

bool GameDataFunction::checkHintSeaOfTree(GameDataHolderAccessor accessor, s32 hintIdx) {}

bool GameDataFunction::checkHintSeaOfTreeMoonRock(GameDataHolderAccessor accessor, s32 hintIdx) {}

s32 GameDataFunction::findUnlockShineNum(bool* isGameClear, GameDataHolderAccessor accessor) {}

s32 GameDataFunction::findUnlockShineNumByWorldId(bool* isGameClear,
                                                  GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::isUnlockedWorld(GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::isUnlockedNextWorld(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isUnlockedAllWorld(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getWorldIndexSpecial2() {}

bool GameDataFunction::isUnlockedCurrentWorld(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isCollectShineForNextWorldAndNotUnlockNextWorld(const al::LiveActor* actor) {

}

const char* GameDataFunction::getMainStageName(GameDataHolderAccessor accessor, s32 worldId) {}

const char* GameDataFunction::tryGetCurrentMainStageName(GameDataHolderAccessor accessor) {}

const char* GameDataFunction::tryGetWorldName(const al::LayoutActor* layout, s32 worldId) {}

const char* GameDataFunction::tryGetWorldNameCurrent(const al::LayoutActor* layout) {}

const char* GameDataFunction::tryGetRegionNameCurrent(const al::LayoutActor* layout) {}

const char* GameDataFunction::getWorldDevelopNameCurrent(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getWorldScenarioNum(GameDataHolderAccessor accessor, s32 worldId) {}

const char* GameDataFunction::findMainStageNameByDevelopName(GameDataHolderAccessor accessor,
                                                             const char* developName) {}

s32 GameDataFunction::findWorldIdByDevelopName(GameDataHolderAccessor accessor,
                                               const char* developName) {}

s32 GameDataFunction::tryFindWorldIdByMainStageName(const al::Scene* scene,
                                                    const char* mainStageName) {}

s32 GameDataFunction::tryFindWorldIdByMainStageName(const al::IUseSceneObjHolder* holder,
                                                    const char* mainStageName) {}

bool GameDataFunction::checkEnableUnlockWorldSpecial1(const al::LiveActor* actor) {}

s32 GameDataFunction::getWorldIndexSpecial1() {}

bool GameDataFunction::checkEnableUnlockWorldSpecial2(const al::LiveActor* actor) {}

const char* GameDataFunction::tryGetWorldNameByFileId(const al::LayoutActor* layout, s32 fileId) {}

bool GameDataFunction::isNewSaveDataByFileId(const al::LayoutActor*, s32 fileId) {}

u64 GameDataFunction::getLastUpdateFileTime(const al::LayoutActor*, s32 fileId) {}

void GameDataFunction::makeTextureSaveDataFileName(sead::BufferedSafeStringBase<char>* fileName,
                                                   const nn::g3d::ResFile* textureSaveData,
                                                   const GameDataHolder* holder, s32 fileId) {}

s32 GameDataFunction::getWorldIndexPeach() {}

s32 GameDataFunction::getWorldIndexCity() {}

bool GameDataFunction::isCityWorldCeremonyAll(s32 worldId, s32 scenarioNo) {}

s32 GameDataFunction::getWorldIndexSea() {}

void GameDataFunction::unlockWorld(GameDataHolderWriter writer, s32 worldId) {}

s32 GameDataFunction::getUnlockWorldIdForWorldMap(const al::LayoutActor* layout, s32 worldId) {}

s32 GameDataFunction::getUnlockWorldIdForWorldMap(const al::LiveActor* actor, s32 worldId) {}

s32 GameDataFunction::getUnlockWorldIdForWorldMap(const al::Scene* scene, s32 worldId) {}

s32 GameDataFunction::getUnlockWorldIdForWorldMap(const GameDataHolder* holder, s32 worldId) {}

s32 GameDataFunction::getUnlockWorldNumForWorldMap(const al::Scene* scene) {}

s32 GameDataFunction::getUnlockWorldNumForWorldMap(const al::LiveActor* actor) {}

s32 GameDataFunction::getUnlockWorldNumForWorldMap(const al::LayoutActor* layout) {}

s32 GameDataFunction::calcNextLockedWorldIdForWorldMap(const al::LayoutActor* layout, s32 worldId) {

}

s32 GameDataFunction::calcNextLockedWorldIdForWorldMap(const al::Scene* scene, s32 worldId) {}

s32 GameDataFunction::calcNextLockedWorldNumForWorldMap(const al::Scene* scene) {}

s32 GameDataFunction::calcNextLockedWorldNumForWorldMap(const al::LayoutActor* layout) {}

s32 GameDataFunction::getWorldIdForShineList(const al::LayoutActor* layout, s32 worldId) {}

s32 GameDataFunction::calcWorldNumForShineList(const al::LayoutActor* layout) {}

s32 GameDataFunction::getLatestUnlockWorldIdForShineTowerMeter(const al::LiveActor* actor) {}

bool GameDataFunction::isClearSandWorldScenario1(const al::Scene* scene) {}

bool GameDataFunction::isClearCityWorldScenario1(const al::Scene* scene) {}

bool GameDataFunction::isClearSkyWorldScenario1(const al::Scene* scene) {}

bool GameDataFunction::isCityWorldScenario2(const al::IUseSceneObjHolder* holder) {}

bool GameDataFunction::isWorldCity(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::calcNextWorldId(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPlayDemoWorldWarp(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPlayDemoWorldWarpHole(GameDataHolderAccessor accessor) {}

void GameDataFunction::noPlayDemoWorldWarp(GameDataHolderWriter writer) {}

bool GameDataFunction::isPlayDemoReturnToHome(GameDataHolderAccessor accessor) {}

void GameDataFunction::requestPlayDemoReturnToHome(GameDataHolderWriter writer) {}

bool GameDataFunction::isPlayDemoAwardSpecial(GameDataHolderAccessor accessor) {}

void GameDataFunction::requestPlayDemoAwardSpecial(GameDataHolderWriter writer) {}

bool GameDataFunction::isPlayDemoLavaErupt(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isPlayDemoPlayerDownForBattleKoopaAfter(GameDataHolderAccessor accessor) {}

void GameDataFunction::disablePlayDemoPlayerDownForBattleKoopaAfter(GameDataHolderWriter writer) {}

void GameDataFunction::enteredStage(GameDataHolderWriter writer) {}

const char* GameDataFunction::getCurrentCostumeTypeName(GameDataHolderAccessor accessor) {}

const char* GameDataFunction::getCurrentCapTypeName(GameDataHolderAccessor accessor) {}

void GameDataFunction::wearCostume(GameDataHolderWriter writer, const char* costumeName) {}

void GameDataFunction::wearCap(GameDataHolderWriter writer, const char* capName) {}

void GameDataFunction::wearCostumeRandom(al::IUseSceneObjHolder* holder) {}

void GameDataFunction::wearCapRandom(al::IUseSceneObjHolder* holder) {}

void GameDataFunction::tryWearCostumeRandomIfEnable(al::IUseSceneObjHolder* holder) {}

bool GameDataFunction::isCostumeRandomMode(al::IUseSceneObjHolder* holder) {}

void GameDataFunction::tryWearCapRandomIfEnable(al::IUseSceneObjHolder* holder) {}

bool GameDataFunction::isCapRandomMode(al::IUseSceneObjHolder* holder) {}

void GameDataFunction::setCostumeRandomMode(al::IUseSceneObjHolder* holder) {}

void GameDataFunction::setCapRandomMode(al::IUseSceneObjHolder* holder) {}

void GameDataFunction::resetCostumeRandomMode(al::IUseSceneObjHolder* holder) {}

void GameDataFunction::resetCapRandomMode(al::IUseSceneObjHolder* holder) {}

sead::PtrArray<ShopItem::ItemInfo>*
GameDataFunction::getShopItemInfoList(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistHackObjInfo(GameDataHolderAccessor accessor, const char* hackName) {}

HackObjInfo* GameDataFunction::getHackObjInfo(GameDataHolderAccessor accessor,
                                              const char* hackName) {}

void GameDataFunction::addHackDictionary(GameDataHolderWriter writer, const char* hackName) {}

bool GameDataFunction::isExistInHackDictionary(GameDataHolderAccessor accessor,
                                               const char* hackName) {}

bool GameDataFunction::isShowHackTutorial(GameDataHolderAccessor accessor, const char* hackName,
                                          const char* suffix) {}

void GameDataFunction::setShowHackTutorial(GameDataHolderWriter writer, const char* hackName,
                                           const char* suffix) {}

bool GameDataFunction::isShowBindTutorial(GameDataHolderAccessor accessor,
                                          const BindInfo& bindInfo) {}

void GameDataFunction::setShowBindTutorial(GameDataHolderWriter writer, const BindInfo& bindInfo) {}

bool GameDataFunction::isGotShine(GameDataHolderAccessor accessor, s32 worldId, s32 shineIdx) {}

bool GameDataFunction::isOpenShineName(const al::LayoutActor* layout, s32 worldId, s32 shineIdx) {}

bool GameDataFunction::checkAchievementShine(const al::LayoutActor* layout, s32 worldId,
                                             s32 shineIdx) {}

s32 GameDataFunction::calcShineNumInOneShine(const al::LayoutActor* layout, s32 worldId,
                                             s32 shineIdx) {}

const char16* GameDataFunction::tryFindShineMessage(const al::LayoutActor* layout, s32 worldId,
                                                    s32 shineIdx) {}

const char16* GameDataFunction::tryFindShineMessage(const al::LiveActor* actor,
                                                    const al::IUseMessageSystem* messageSystem,
                                                    s32 worldId, s32 shineIdx) {}

u64 GameDataFunction::findShineGetTime(const al::LayoutActor* layout, s32 worldId, s32 shineIdx) {}

bool GameDataFunction::checkMoonRockShineForShineList(const al::LayoutActor* layout, s32 worldId,
                                                      s32 shineIdx) {}

bool GameDataFunction::checkUnlockHintByHintNpcForShineList(const al::LayoutActor* layout,
                                                            s32 worldId, s32 shineIdx) {}

bool GameDataFunction::checkUnlockHintByAmiiboForShineList(const al::LayoutActor* layout,
                                                           s32 worldId, s32 shineIdx) {}

bool GameDataFunction::checkShineSeaOfTreeForShineList(const al::LayoutActor* layout, s32 worldId,
                                                       s32 shineIdx) {}

s32 GameDataFunction::getWorldTotalShineNum(GameDataHolderAccessor accessor, s32 worldId) {}

s32 GameDataFunction::getWorldTotalShineNumMax(GameDataHolderAccessor accessor, s32 worldId) {}

void GameDataFunction::findShineTrans(sead::Vector3f* trans, GameDataHolderAccessor accessor,
                                      s32 worldId, s32 shineIdx) {}

sead::Vector3f* GameDataFunction::getHomeTrans(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistHome(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isActivateHome(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getMiniGameNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getMiniGameNumMax(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getMiniGameTrans(GameDataHolderAccessor accessor,
                                                   s32 miniGameIdx) {}

const char* GameDataFunction::getMiniGameName(GameDataHolderAccessor accessor, s32 miniGameIdx) {}

sead::Vector3f* GameDataFunction::getRaceStartTrans(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getRaceGoalTrans(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getHintNpcTrans(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getShopNpcTrans(GameDataHolderAccessor accessor, s32 shopNpcIdx) {

}

bool GameDataFunction::isShopSellout(GameDataHolderAccessor accessor, s32 shopNpcIdx) {}

s32 GameDataFunction::calcShopNum(GameDataHolderAccessor accessor) {}

s32 GameDataFunction::getShopNpcIconNumMax(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistRaceStartNpc(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistHintNpc(GameDataHolderAccessor accessor) {}

sead::Matrix34f* GameDataFunction::getCurrentMapView(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistJango(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getJangoTrans(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistAmiiboNpc(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getAmiiboNpcTrans(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isInInvalidOpenMapStage(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getStageMapPlayerPos(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistTimeBalloonNpc(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getTimeBalloonNpcTrans(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isExistPoetter(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getPoetterTrans(GameDataHolderAccessor accessor) {}

sead::Vector3f* GameDataFunction::getMoonRockTrans(GameDataHolderAccessor accessor) {}

void GameDataFunction::setHomeTrans(const al::LiveActor* actor, const sead::Vector3f& trans) {}

void GameDataFunction::setRaceStartNpcTrans(const al::LiveActor* actor) {}

void GameDataFunction::setRaceStartTrans(const al::LiveActor* actor) {}

void GameDataFunction::setRaceGoalTrans(const al::LiveActor* actor) {}

void GameDataFunction::setHintNpcTrans(const al::LiveActor* actor) {}

void GameDataFunction::setJangoTrans(const al::LiveActor* actor) {}

void GameDataFunction::disableJangoTrans(const al::LiveActor* actor) {}

void GameDataFunction::setAmiiboNpcTrans(const al::LiveActor* actor) {}

void GameDataFunction::setShopNpcTrans(const al::LiveActor* actor, const char* storeName,
                                       s32 shopNpcIdx) {}

void GameDataFunction::setShopNpcTrans(GameDataHolderAccessor accessor,
                                       const al::PlacementInfo& placementInfo) {}

void GameDataFunction::setMiniGameInfo(GameDataHolderAccessor accessor,
                                       const al::PlacementInfo& placementInfo) {}

void GameDataFunction::setTimeBalloonTrans(GameDataHolderAccessor accessor,
                                           const sead::Vector3f& trans) {}

void GameDataFunction::setPoetterTrans(GameDataHolderAccessor accessor,
                                       const sead::Vector3f& trans) {}

void GameDataFunction::setStageMapPlayerPos(GameDataHolderWriter writer,
                                            const sead::Vector3f& trans) {}

void GameDataFunction::setMoonRockTrans(GameDataHolderWriter writer, const sead::Vector3f& trans) {}

s32 GameDataFunction::getHomeLevel(GameDataHolderAccessor accessor) {}

void GameDataFunction::upHomeLevel(GameDataHolderWriter writer) {}

void GameDataFunction::activateHome(GameDataHolderWriter writer) {}

bool GameDataFunction::isLaunchHome(GameDataHolderAccessor accessor) {}

void GameDataFunction::launchHome(GameDataHolderWriter writer) {}

bool GameDataFunction::isCrashHome(GameDataHolderAccessor accessor) {}

void GameDataFunction::crashHome(GameDataHolderWriter writer) {}

bool GameDataFunction::isRepairHome(GameDataHolderAccessor accessor) {}

void GameDataFunction::repairHome(GameDataHolderWriter writer) {}

bool GameDataFunction::isBossAttackedHome(GameDataHolderAccessor accessor) {}

void GameDataFunction::bossAttackHome(GameDataHolderWriter writer) {}

bool GameDataFunction::isRepairHomeByCrashedBoss(GameDataHolderAccessor accessor) {}

void GameDataFunction::repairHomeByCrashedBoss(GameDataHolderWriter writer) {}

bool GameDataFunction::isFindKoopaNext(GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::isBossAttackedHomeNext(GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::isFindKoopa(GameDataHolderAccessor accessor) {}

void GameDataFunction::findKoopa(GameDataHolderWriter writer) {}

bool GameDataFunction::isEnableCap(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isMeetCap(GameDataHolderAccessor accessor) {}

void GameDataFunction::enableCap(GameDataHolderWriter writer) {}

void GameDataFunction::disableCapByPlacement(const al::LiveActor* actor) {}

bool GameDataFunction::isTalkedCapNearHomeInWaterfall(const al::LiveActor* actor) {}

void GameDataFunction::talkCapNearHomeInWaterfall(const al::LiveActor* actor) {}

bool GameDataFunction::isFlagOnTalkMessageInfo(const al::IUseSceneObjHolder* holder,
                                               s32 talkMessageIdx) {}

void GameDataFunction::onFlagTalkMessageInfo(const al::IUseSceneObjHolder* holder,
                                             s32 talkMessageIdx) {}

s32 GameDataFunction::getWorldIndexHat() {}

s32 GameDataFunction::getWorldIndexWaterfall() {}

s32 GameDataFunction::getWorldIndexSand() {}

s32 GameDataFunction::getWorldIndexForest() {}

s32 GameDataFunction::getWorldIndexLake() {}

s32 GameDataFunction::getWorldIndexCloud() {}

s32 GameDataFunction::getWorldIndexClash() {}

s32 GameDataFunction::getWorldIndexSnow() {}

s32 GameDataFunction::getWorldIndexLava() {}

s32 GameDataFunction::getWorldIndexBoss() {}

s32 GameDataFunction::getWorldIndexSky() {}

s32 GameDataFunction::getWorldIndexMoon() {}

bool GameDataFunction::isWorldCap(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldWaterfall(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldSand(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldForest(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldLake(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldCloud(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldClash(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldSnow(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldSea(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldBoss(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldSky(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldMoon(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldPeach(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldSpecial1(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldSpecial2(GameDataHolderAccessor accessor) {}

bool GameDataFunction::isWorldTypeMoon(GameDataHolderAccessor accessor, s32 worldId) {}

bool GameDataFunction::isSnowMainScenario1(const al::IUseSceneObjHolder* holder) {}

bool GameDataFunction::isSnowMainScenario2(const al::IUseSceneObjHolder* holder) {}

bool GameDataFunction::isHomeShipStage(const GameDataHolder* holder) {}

const char* GameDataFunction::getHomeShipStageName() {}

bool GameDataFunction::isCityWorldCeremonyAgain(s32 worldId, s32 scenarioNo) {}

bool GameDataFunction::isGoToCeremonyFromInsideHomeShip(GameDataHolderAccessor accessor) {}

void GameDataFunction::registerScenarioStartCameraInfo(const ScenarioStartCamera* cameraInfo, s32,
                                                       al::CameraTicket* ticket) {}

bool GameDataFunction::isEnableExplainAmiibo(GameDataHolderAccessor accessor) {}

void GameDataFunction::endExplainAmiibo(GameDataHolderWriter writer) {}

void GameDataFunction::startSearchHintByAmiibo(GameDataHolderWriter writer) {}

void GameDataFunction::endSearchHintByAmiibo(GameDataHolderWriter writer) {}

void GameDataFunction::setKidsModeOn(const al::Scene* scene) {}

void GameDataFunction::setKidsModeOff(const al::Scene* scene) {}

bool GameDataFunction::isCollectedBgm(GameDataHolderAccessor accessor, const char* resourceName,
                                      const char* situationName) {}

CollectBgm* GameDataFunction::getCollectBgmByIndex(GameDataHolderAccessor accessor, s32 bgmIdx) {}

void GameDataFunction::trySetCollectedBgm(GameDataHolderWriter writer, const char* resourceName,
                                          const char* situationName) {}

s32 GameDataFunction::getCollectedBgmNum(GameDataHolderWriter writer) {}

void GameDataFunction::registerShineInfo(GameDataHolderAccessor accessor,
                                         const ShineInfo* shineInfo, const sead::Vector3f& trans) {}

void GameDataFunction::setHintTrans(GameDataHolderAccessor accessor, s32 shineIdx,
                                    const sead::Vector3f& trans) {}

void GameDataFunction::resetHintTrans(GameDataHolderAccessor accessor, s32 shineIdx) {}

bool GameDataFunction::isKoopaLv3(GameDataHolderAccessor accessor) {}
