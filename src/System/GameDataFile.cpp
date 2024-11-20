#include "System/GameDataFile.h"

#include "Library/Base/StringUtil.h"
#include "Library/Placement/PlacementId.h"

#include "MapObj/ChangeStageInfo.h"
#include "System/GameDataFunction.h"
#include "System/WorldList.h"
#include "Util/ScenePrepoFunction.h"

void GameDataFile::HintInfo::clear() {
    mStageName.clear();
    mObjId.clear();
    //    mScenarioName.clear();
    mObjectName = nullptr;
    mHintTrans = sead::Vector3f::zero;
    mTrans = sead::Vector3f::zero;
    mMainScenarioNo = -1;
    mWorldId = -1;
    mUniqueId = -1;
    mIsMoonRock = false;
    mIsGet = false;
    mGetTime = 0;
    mHintStatus = HintStatus::NONE;
    mIsAchievement = false;
    mIsGrand = false;
    mStatus = 0;
    mIsShopMoon = false;
    field_1f4 = 0;

    mOptionalId.clear();
    mProgressBitFlag = 0;
    mDisableHintById = false;
    unkBool3 = false;
}

bool GameDataFile::HintInfo::isDisableByWorldWarpHole(bool condition) const {
    if (!condition && al::isEqualString(mOptionalId.cstr(), "WorldWarpHoleShine"))
        return true;
    return false;
}

bool GameDataFile::HintInfo::testFunc(s32 curWorldId, bool isGameClear, s32 scenarioNo,
                                      bool isInWorld) const {
    if (isDisableByWorldWarpHole(isInWorld))
        return false;
    if (mWorldId != curWorldId || mDisableHintById || isGameClear)
        return false;
    if (mProgressBitFlag.countOnBit())
        return mProgressBitFlag.isOnBit(scenarioNo - 1);
    return true;
}

bool GameDataFile::HintInfo::isEnableUnlock(s32 curWorldId, bool isGameClear, s32 scenarioNo,
                                            bool isInWorld) const {
    if (testFunc(curWorldId, isGameClear, scenarioNo, isInWorld)) {
        if (mIsGet)
            return false;

        if (mHintStatus == HintStatus::NONE)
            return true;

        if (isGameClear && mIsMoonRock)
            return false;
        else if (!isGameClear && mIsMoonRock)
            return true;
    }

    return false;
}

bool GameDataFile::HintInfo::isHintStatusUnlock(s32 curWorldId, s32 scenarioNo,
                                                bool isInWorld) const {
    if (mWorldId != curWorldId || mIsGet || mHintStatus != HintStatus::NONE ||
        (isInWorld ? !mIsMoonRock : mIsMoonRock))
        return false;

    return !GameDataFunction::isCityWorldCeremonyAll(curWorldId, scenarioNo) || unkBool3;
}

bool GameDataFile::HintInfo::isHintStatusUnlockByNpc() const {
    return mHintStatus == HintStatus::NPC && !mIsMoonRock;
}

bool GameDataFile::HintInfo::isHintStatusUnlockByAmiibo() const {
    return mHintStatus == HintStatus::AMIIBO;
}

bool GameDataFile::HintInfo::isEnableNameUnlockByScenario(s32 curWorldId, s32 scenarioNo,
                                                          bool isInWorld) const {
    if (isDisableByWorldWarpHole(isInWorld))
        return false;
    if (mWorldId != curWorldId || mDisableHintById)
        return false;
    if (mProgressBitFlag.countOnBit())
        return mProgressBitFlag.isOnBit(scenarioNo - 1);
    return true;
}

GameDataFile::GameDataFile(GameDataHolder* gameDataHolder) {}

void GameDataFile::initializeData() {}

bool GameDataFile::tryReadByamlData(const u8* data) {}

GameDataFile::CoinCollectInfo* GameDataFile::tryFindCoinCollectInfo(const char*,
                                                                    const char*) const {}

s32 GameDataFile::tryFindShineIndexByUniqueId(s32 uniqueId) const {
    for (s32 i = 0; i < 0x400; i++)
        if (mHintInfo[i]->mUniqueId == uniqueId)
            return i;

    return -1;
}

s32 GameDataFile::tryFindCoinCollectIndexByUniqueId(s32 uniqueId) const {}

void GameDataFile::buyDefaultItem() {}

void GameDataFile::unlockAchievementShineName() {}

bool GameDataFile::isKidsMode() const {
    return mIsKidsMode;
}

void GameDataFile::updateWorldMapIndex() {}

void GameDataFile::updateWorldWarpIndex() {}

s32 GameDataFile::getScenarioNo(s32 worldId) const {
    return mScenarioNos[worldId];
}

s32 GameDataFile::getMainScenarioNo(s32 worldId) const {
    return mQuests[worldId];
}

bool GameDataFile::isEmpty() const {
    return mIsPlayDemoOpening;
}

void GameDataFile::initializeCheckpointTable() {}

void GameDataFile::generateSaveDataIdForPrepo() {
    mSaveDataIdForPrepo = rs::prepo::generateSaveDataId();
}

void GameDataFile::resetMapIcon() {}

void GameDataFile::wearDefault() {
    mCurrentClothName.format("Mario");
    mCurrentCapName.format("Mario");
}

void GameDataFile::initializeHintList() {}

void GameDataFile::initializeCoinCollectList() {}

void GameDataFile::resetTempData() {}

bool GameDataFile::isGameClear() const {
    return isUnlockedWorld(GameDataFunction::getWorldIndexPeach()) &&
           isAlreadyGoWorld(GameDataFunction::getWorldIndexPeach());
}

bool GameDataFile::isUnlockedWorld(s32 worldId) const {
    return mGameProgressData->isUnlockWorld(worldId);
}

bool GameDataFile::isAlreadyGoWorld(s32 worldId) const {
    return mGameProgressData->isAlreadyGoWorld(worldId);
}

void GameDataFile::addPlayTime(s32 amount, const al::IUseSceneObjHolder* sceneObjHolder) {
    mPlayTimeTotal += amount;
}

u64 GameDataFile::getPlayTimeTotal() const {
    return mPlayTimeTotal;
}

void GameDataFile::updateSaveTime() {
    sead::DateTime time(0);
    time.setNow();
    mSaveTime = time;
}

void GameDataFile::updateSaveTimeForDisp() {
    mLastUpdateTime = mSaveTime;
}

void GameDataFile::updateSaveInfoForDisp() {}

u64 GameDataFile::getLastUpdateTime() const {
    return mLastUpdateTime.getUnixTime();
}

void GameDataFile::generateSaveDataIdForPrepoForWrite() {
    mSaveDataIdForPrepoForWrite = rs::prepo::generateSaveDataId();
}

void GameDataFile::resetSaveDataIdForPrepoForWrite() {
    mSaveDataIdForPrepoForWrite = mSaveDataIdForPrepo;
}

void GameDataFile::startStage(const char* stageName, s32 scenarioNo) {}

bool GameDataFile::isRaceStart() const {
    return field_a44 != 0;
}

bool GameDataFile::checkIsHomeStage(const char* stageName) const {
    return mGameDataHolder->mWorldList->tryFindWorldIndexByMainStageName(stageName) != -1;
}

void GameDataFile::setGameClear() {
    mQuests[GameDataFunction::getWorldIndexMoon()] = 0;
    s32 scenarioNo = mScenarioNos[GameDataFunction::getWorldIndexPeach()];
    if (scenarioNo < 3)
        scenarioNo = 2;
    mScenarioNos[GameDataFunction::getWorldIndexPeach()] = scenarioNo;
}

// NON-MATCHING
void GameDataFile::setOriginalHintTrans(s32 shineIdx) {
    sead::Vector3f* hintTrans = &mHintInfo[shineIdx]->mHintTrans;
    s32 worldId = mHintInfo[shineIdx]->mWorldId;
    if (worldId < 1)
        worldId = 0;
    if (!mGameDataHolder->mWorldList->tryFindHintTransByScenarioNo(
            hintTrans, mHintInfo[shineIdx]->mUniqueId, mScenarioNos[worldId])) {
        *hintTrans = mHintInfo[shineIdx]->mTrans;
    }
}

PlayerHitPointData* GameDataFile::getPlayerHitPointData() const {
    return mHitPointData;
}

void GameDataFile::startDemoStage(const char* stageName) {
    mStageNameCurrent.format("%s", stageName);
}

void GameDataFile::changeNextStage(const ChangeStageInfo* stageInfo, StageStart stageStart) {}

void GameDataFile::returnPrevStage() {}

void GameDataFile::changeNextStageWithDemoWorldWarp(const char* stageName) {}

void GameDataFile::changeNextStageWithWorldWarpHole(const char* stageName) {}

void GameDataFile::restartStage() {
    field_a09 = false;
    if (mCheckpointName.isEmpty())
        return;

    mPlayerStartId.clear();
    field_160.clear();
    mStageNameNext.format("%s", mWorldStageName.cstr());
}

s32 GameDataFile::calcNextScenarioNo() const {}

const char* GameDataFile::getStageNameCurrent() const {
    return mStageNameCurrent.cstr();
}

const char* GameDataFile::tryGetStageNameCurrent() const {
    if (mStageNameCurrent.isEmpty())
        return nullptr;

    const char* stageName = mStageNameCurrent.cstr();
    if (al::isEqualString(stageName, ""))
        return nullptr;

    return stageName;
}

const char* GameDataFile::getStageNameNext() const {
    if (mStageNameNext.isEmpty())
        return nullptr;

    const char* stageName = mStageNameNext.cstr();
    if (al::isEqualString(stageName, ""))
        return nullptr;

    return stageName;
}

void GameDataFile::changeWipeType(const char* wipeName) {
    field_a30->setWipeType(wipeName);
}

void GameDataFile::setActivateHome() {
    mGameProgressData->activateHome();
}

bool GameDataFile::isGoToCeremonyFromInsideHomeShip() const {
    if (al::isEqualString(getStageNameCurrent(), GameDataFunction::getHomeShipStageName()) &&
        field_a28 != -1)
        return true;

    return false;
}

const char* GameDataFile::getPlayerStartId() const {
    if (mPlayerStartId.isEmpty())
        return nullptr;

    const char* startId = mPlayerStartId.cstr();
    if (al::isEqualString(startId, ""))
        return nullptr;

    return startId;
}

void GameDataFile::setCheckpointId(const al::PlacementId* checkpoint) {}

void GameDataFile::setRestartPointId(const al::PlacementId* restartPoint) {
    field_160.clear();
    mPlayerStartId.clear();
    restartPoint->makeString(&field_908);
}

void GameDataFile::clearStartId() {
    field_160.clear();
    mPlayerStartId.clear();
    field_908.clear();
    mCheckpointName.clear();
    mWorldStageName.clear();
}

// NON-MATCHING
const char* GameDataFile::tryGetRestartPointIdString() const {
    const char* str;
    if (!field_908.isEmpty())
        str = field_908.cstr();
    else if (!mCheckpointName.isEmpty())
        str = mCheckpointName.cstr();
    else
        return nullptr;

    if (al::isEqualString(str, ""))
        return nullptr;

    return str;
}

void GameDataFile::endStage() {
    field_a09 = false;
    mStageNamePrevious.format("%s", getStageNameCurrent());
    mCheckpointName.clear();
}

void GameDataFile::missAndRestartStage() {}

void GameDataFile::setMissRestartInfo(const al::PlacementInfo& missRestartInfo) {
    mMissRestartInfo->init(missRestartInfo, mGameDataHolder);
    mIsUseMissRestartInfo = true;
}

bool GameDataFile::isUseMissRestartInfo() const {
    return mIsUseMissRestartInfo;
}

bool GameDataFile::isFirstTimeNextWorld() const {
    return mGameProgressData->isFirstTimeGoWorld(mNextWorldId);
}

void GameDataFile::getAchievement(const char* achievementName) {}

bool GameDataFile::isGotShine(const ShineInfo* shineInfo) const {}

// NON-MATCHING
bool GameDataFile::isGotShine(s32 shineIdx) const {
    if (shineIdx > 1023)
        return false;

    return mHintInfo[shineIdx]->mIsGet;
}

bool GameDataFile::checkGotShine(const char* objId) const {}

void GameDataFile::setGotShine(const ShineInfo* shineInfo) {}

s32 GameDataFile::getShineNum() const {
    return getShineNum(mWorldId);
}

s32 GameDataFile::getShineNum(s32 worldId) const {
    if (worldId < 1)
        worldId = 0;
    return mShineNum[worldId];
}

s32 GameDataFile::getTotalShineNum() const {
    s32 num = 0;
    for (s32 i = 0; i < 20; i++)
        num += mShineNum[i];
    return num;
}

s32 GameDataFile::getTotalShopShineNum() const {
    s32 num = 0;
    for (s32 i = 0; i < 20; i++)
        num += mShopShineNum[i];
    return num;
}

bool GameDataFile::tryGetNextMainScenarioLabel(sead::BufferedSafeString*,
                                               sead::BufferedSafeString*) const {}

bool GameDataFile::tryGetNextMainScenarioPos(sead::Vector3f* pos) const {}

GameDataFile::HintInfo* GameDataFile::tryFindNextMainScenarioInfo() const {}

void GameDataFile::addPayShine(s32 count) {
    s32 worldId = mWorldId;
    if (worldId < 1)
        worldId = 0;

    mPayShineNums[worldId] += count;
    GameDataHolderAccessor accessor(mGameDataHolder);
    if (GameDataFunction::calcIsGetShineAllInAllWorld(accessor))
        mIsPayShineAllInAllWorld = true;
}

void GameDataFile::addPayShineCurrentAll() {}

s32 GameDataFile::getPayShineNum(s32 worldId) const {}

s32 GameDataFile::getTotalPayShineNum() const {}

bool GameDataFile::isPayShineAllInAllWorld() const {}

void GameDataFile::addKey(s32 count) {}

s32 GameDataFile::getKeyNum() const {}

void GameDataFile::addOpenDoorLockNum(s32 count) {}

void GameDataFile::setStartedObj(const al::PlacementId* obj) {}

bool GameDataFile::isStartedObj(const al::PlacementId* obj, const char* outStageName) const {}

bool GameDataFile::isStartedObj(const char* stageName, const char* objId) const {}

void GameDataFile::setSaveObjS32(const al::PlacementId* obj, s32) {}

UniqObjInfo* GameDataFile::tryFindSaveObjS32(const al::PlacementId* obj) {}

bool GameDataFile::isExistSessionMember(const SessionMusicianType& memberType) const {}

void GameDataFile::addSessionMember(const SessionMusicianType& memberType) {}

void GameDataFile::addCoinCollect(const al::PlacementId* coinCollect) {}

bool GameDataFile::isGotCoinCollect(const al::PlacementId* coinCollect) const {}

s32 GameDataFile::getCoinCollectNum() const {}

s32 GameDataFile::getCoinCollectGotNum() const {}

s32 GameDataFile::getCoinCollectGotNum(s32 worldId) const {}

void GameDataFile::useCoinCollect(s32 count) {}

const char* GameDataFile::tryFindExistCoinCollectStageName(s32 worldId) const {}

void GameDataFile::payCoinToSphinx() {}

bool GameDataFile::isPayCoinToSphinx() const {}

void GameDataFile::answerCorrectSphinxQuiz() {}

void GameDataFile::answerCorrectSphinxQuizAll() {}

bool GameDataFile::isAnswerCorrectSphinxQuiz(s32 worldId) const {}

bool GameDataFile::isAnswerCorrectSphinxQuizAll(s32 worldId) const {}

bool GameDataFile::isTalkAlreadyLocalLanguage() const {}

void GameDataFile::talkLocalLanguage() {}

bool GameDataFile::isFirstWorldTravelingStatus() const {}

void GameDataFile::saveWorldTravelingStatus(const char* progressName) {}

const char* GameDataFile::getWorldTravelingStatus() const {}

bool GameDataFile::isStartWorldTravelingPeach() const {}

void GameDataFile::startWorldTravelingPeach() {}

void GameDataFile::setGrowFlowerTime(const al::PlacementId* flowerPot, const al::PlacementId*,
                                     u64 timestamp) {}

void GameDataFile::setGrowFlowerTime(const al::PlacementId* flowerPot, u64 timestamp) {}

u64 GameDataFile::getGrowFlowerTime(const al::PlacementId* flowerPot) const {}

void GameDataFile::addGrowFlowerGrowLevel(const al::PlacementId* flowerPot, u32 count) {}

s32 GameDataFile::getGrowFlowerGrowLevel(const al::PlacementId* flowerPot) const {}

bool GameDataFile::isUsedGrowFlowerSeed(const al::PlacementId* flowerSeed) const {}

const char* GameDataFile::findGrowFlowerPotIdFromSeedId(const al::PlacementId* flowerSeed) {}

void GameDataFile::addCoin(s32 count) {}

void GameDataFile::addPlayerJumpCount() {}

s32 GameDataFile::getPlayerJumpCount() const {}

void GameDataFile::addPlayerThrowCapCount() {}

s32 GameDataFile::getPlayerThrowCapCount() const {}

bool GameDataFile::readFromStream(sead::ReadStream* stream, u8* data) {}

bool GameDataFile::tryReadByamlDataFromStream(sead::ReadStream* stream, u8* data, s32) {}

void GameDataFile::writeToStream(sead::WriteStream* stream, sead::Heap* heap) const {}

bool GameDataFile::tryWriteByByaml(sead::WriteStream* stream, sead::Heap* heap) const {}

bool GameDataFile::isPlayDemoPlayerDownForBattleKoopaAfter() const {}

s32 GameDataFile::getCheckpointNumMaxInWorld() const {}

sead::Vector3f* GameDataFile::getCheckpointTransInWorld(const char* objId) const {}

bool GameDataFile::isGotCheckpointInWorld(s32 worldId) const {}

s32 GameDataFile::calcCheckpointIndexInScenario(s32) const {}

const char* GameDataFile::getCheckpointObjIdInWorld(s32 checkpointIdx) const {}

bool GameDataFile::isGotCheckpoint(al::PlacementId* checkpoint) const {}

void GameDataFile::changeNextSceneByGotCheckpoint(s32 checkpointIdx) {}

void GameDataFile::changeNextSceneByWarp() {}

void GameDataFile::changeNextSceneByHome() {}

void GameDataFile::startYukimaruRace() {}

void GameDataFile::startYukimaruRaceTutorial() {}

void GameDataFile::startRaceManRace() {}

void GameDataFile::registerCheckpointTrans(const al::PlacementId* checkpoint,
                                           const sead::Vector3f& trans) {}

s32 GameDataFile::calcGetCheckpointNum() const {}

bool GameDataFile::isEnableUnlockHint() const {}

s32 GameDataFile::calcRestHintNum() const {}

void GameDataFile::unlockHint() {}

void GameDataFile::unlockHintImpl(s32) {}

void GameDataFile::unlockHintAmiibo() {}

void GameDataFile::unlockHintAddByMoonRock() {}

s32 GameDataFile::calcHintNum() const {}

sead::Vector3f* GameDataFile::calcHintTrans(s32) const {}

GameDataFile::HintInfo* GameDataFile::findHint(s32) const {}

sead::Vector3f* GameDataFile::calcHintTransMostEasy() const {}

GameDataFile::HintInfo* GameDataFile::findHintInfoMostEasy() const {}

s32 GameDataFile::calcHintMoonRockNum() const {}

sead::Vector3f* GameDataFile::calcHintMoonRockTrans(s32) const {}

GameDataFile::HintInfo* GameDataFile::findHintMoonRock(s32) const {}

bool GameDataFile::tryUnlockShineName(s32 worldId, s32 shineIdx) {}

bool GameDataFile::isOpenMoonRock(s32 worldId) const {}

void GameDataFile::calcShineIndexTableNameAvailable(s32*, s32*, s32 worldId) {}

void GameDataFile::calcShineIndexTableNameUnlockable(s32*, s32*, s32 worldId) {}

bool GameDataFile::isUnlockAchievementShineName() const {}

void GameDataFile::unlockWorld(s32 worldId) {}

void GameDataFile::noPlayDemoWorldWarp() {}

s32 GameDataFile::calcWorldWarpHoleThroughNum() const {}

s32 GameDataFile::getWorldWarpHoleThroughNumMax() const {}

void GameDataFile::enteredStage() {}

void GameDataFile::buyItem(const ShopItem::ItemInfo* itemInfo, bool) {}

sead::FixedSafeString<64>* GameDataFile::tryFindItemList(const ShopItem::ItemInfo* itemInfo) const {

}

s32 GameDataFile::calcHaveClothNum() const {}

s32 GameDataFile::calcHaveCapNum() const {}

s32 GameDataFile::calcHaveStickerNum() const {}

s32 GameDataFile::calcHaveGiftNum() const {}

bool GameDataFile::isBuyItem(const ShopItem::ItemInfo* itemInfo) const {}

bool GameDataFile::isBuyItem(const char* itemName, const sead::FixedSafeString<64>*) const {}

void GameDataFile::buyItemAll() {}

void GameDataFile::wearCostume(const char* costumeName) {}

void GameDataFile::wearCap(const char* capName) {}

void GameDataFile::addHackDictionary(const char* hackName) {}

bool GameDataFile::isExistInHackDictionary(const char* hackName) const {}

GameDataFile::HintInfo* GameDataFile::findShine(s32 worldId, s32 shineIdx) const {}

bool GameDataFile::isGotShine(s32 worldId, s32 shineIdx) const {}

bool GameDataFile::isOpenShineName(s32 worldId, s32 shineIdx) const {}

s32 GameDataFile::calcShineNumInOneShine(s32 worldId, s32 shineIdx) const {}

bool GameDataFile::checkAchievementShine(s32, s32) const {}

s32 GameDataFile::getWorldTotalShineNum(s32 worldId) const {}

s32 GameDataFile::getWorldTotalShineNumMax(s32 worldId) const {}

void GameDataFile::winRace() {}

RaceRecord* GameDataFile::findRaceRecord(const char* raceName) const {}

void GameDataFile::incrementRaceLoseCount(s32 level) {}

s32 GameDataFile::getRaceLoseCount(s32 level) const {}

void GameDataFile::setJumpingRopeBestCount(s32 bestCount) {}

void GameDataFile::setUpdateJumpingRopeScoreFlag() {}

void GameDataFile::setVolleyballBestCount(s32 bestCount) {}

void GameDataFile::setUpdateVolleyballScoreFlag() {}

bool GameDataFile::isExistJango() const {}

void GameDataFile::setJangoTrans(const sead::Vector3f& trans) {}

void GameDataFile::setAmiiboNpcTrans(const sead::Vector3f& trans) {}

void GameDataFile::setTimeBalloonNpcTrans(const sead::Vector3f& trans) {}

void GameDataFile::setPoetterTrans(const sead::Vector3f& trans) {}

void GameDataFile::setShopNpcTrans(const sead::Vector3f& trans, const char* storeName, s32) {}

void GameDataFile::setMoonRockTrans(const sead::Vector3f& trans) {}

void GameDataFile::setMiniGameInfo(const sead::Vector3f& trans, const char* name) {}

s32 GameDataFile::calcMiniGameNum() const {}

s32 GameDataFile::getMiniGameNumMax() const {}

sead::Vector3f* GameDataFile::getMiniGameTrans(s32 idx) const {}

const char* GameDataFile::getMiniGameName(s32 idx) const {}

bool GameDataFile::isExistTimeBalloonNpc() const {}

sead::Vector3f* GameDataFile::getTimeBalloonNpcTrans() const {}

bool GameDataFile::isExistPoetter() const {}

sead::Vector3f* GameDataFile::getPoetterTrans() const {}

bool GameDataFile::isAlreadyShowExplainCheckpointFlag() const {}

void GameDataFile::showExplainCheckpointFlag() {}

sead::Vector3f* GameDataFile::getShopNpcTrans(s32 idx) const {}

bool GameDataFile::isShopSellout(s32 idx) const {}

s32 GameDataFile::calcShopNum() const {}

s32 GameDataFile::getShopNpcIconNumMax() const {}

s32 GameDataFile::getScenarioNo() const {}

s32 GameDataFile::getScenarioNoPlacement() const {}

bool GameDataFile::isClearWorldMainScenario(s32 worldId) const {}

bool GameDataFile::isFlagOnTalkMessageInfo(s32) const {}

void GameDataFile::setFlagOnTalkMessageInfo(s32) {}

bool GameDataFile::isTalkKakku() const {}

void GameDataFile::talkKakku() {}

bool GameDataFile::isTalkWorldTravelingPeach() const {}

void GameDataFile::talkWorldTravelingPeach() {}

bool GameDataFile::isTalkCollectBgmNpc() const {}

void GameDataFile::talkCollectBgmNpc() {}

s32 GameDataFile::getTokimekiMayorNpcFavorabilityRating() const {}

void GameDataFile::setTokimekiMayorNpcFavorabilityRating(s32 rating) {}

bool GameDataFile::isFirstNetwork() const {}

void GameDataFile::noFirstNetwork() {}

void GameDataFile::setKidsMode(bool isKidsMode) {}

bool GameDataFile::isPlayScenarioCamera(const QuestInfo*) const {}

bool GameDataFile::isNextMainShine(const QuestInfo*) const {}

bool GameDataFile::isNextMainShine(s32 shineIdx) const {}

bool GameDataFile::isMainShine(s32 shineIdx) const {}

bool GameDataFile::isLatestGetMainShine(const ShineInfo* shineInfo) const {}

bool GameDataFile::calcIsGetMainShineAll(const al::IUseSceneObjHolder* sceneObjHolder) const {}

bool GameDataFile::calcIsGetShineAllInWorld(s32 worldId) const {}

s32 GameDataFile::tryFindLinkedShineIndex(const al::ActorInitInfo& actorInitInfo,
                                          const al::IUseSceneObjHolder* sceneObjHolder) const {}

s32 GameDataFile::tryFindLinkedShineIndex(const al::ActorInitInfo& actorInitInfo, s32,
                                          const al::IUseSceneObjHolder* sceneObjHolder) const {}

s32 GameDataFile::tryFindLinkedShineIndexByLinkName(const al::IUseSceneObjHolder* sceneObjHolder,
                                                    const al::ActorInitInfo& actorInitInfo,
                                                    const char* linkName) const {}

s32 GameDataFile::calcLinkedShineNum(const al::ActorInitInfo& actorInitInfo) const {}

s32 GameDataFile::tryFindShineIndex(const al::ActorInitInfo& actorInitInfo) const {}

s32 GameDataFile::tryFindShineIndex(const char* stageName, const char* objId) const {}

void GameDataFile::disableHintById(s32 shineIdx) {}

void GameDataFile::enableHintById(s32 shineIdx) {}

void GameDataFile::setStartShine(const ShineInfo* shineInfo) {}

s32 GameDataFile::getStartShineNextIndex() const {}

void GameDataFile::setHintTrans(s32 shineIdx, const sead::Vector3f& trans) {}

void GameDataFile::resetHintTrans(s32 shineIdx) {}

void GameDataFile::registerShineInfo(const ShineInfo* shineInfo, const sead::Vector3f& trans) {}

s32 GameDataFile::calcRestShineInStageWithWorldProgress(const char* stageName) const {}

s32 GameDataFile::calcGetShineNumByObjectNameOrOptionalId(const char* objNameOrOptionalId,
                                                          GameDataFile::CountType countType) const {

}

s32 GameDataFile::calcGetShineNumByObjectNameWithWorldId(const char* objName, s32 worldId) const {}

s32 GameDataFile::calcAllShineNumByObjectNameOrOptionalId(const char* objNameOrOptionalId) const {}

s32 GameDataFile::calcGetShineNumByStageName(const char* stageName) const {}

bool GameDataFile::tryFindAndInitShineInfoByOptionalId(ShineInfo* shineInfo,
                                                       const char* optionalId) {}

s32 GameDataFile::tryFindUniqueId(const ShineInfo* shineInfo) const {}

s32 GameDataFile::findUnlockShineNumCurrentWorld(bool*) const {}

s32 GameDataFile::getMainScenarioNoCurrent() const {}

void GameDataFile::setMainScenarioNo(s32) {}

bool GameDataFile::isCollectedBgm(const char* bgmName, const char* bgmSituationName) const {}

CollectBgm* GameDataFile::getCollectBgmByIndex(s32 idx) const {}

bool GameDataFile::trySetCollectedBgm(const char* bgmName, const char* bgmSituationName) {}

s32 GameDataFile::getCollectedBgmNum() const {}

s32 GameDataFile::getCollectedBgmMaxNum() const {}

void GameDataFile::setGotShine(s32 shineIdx) {}

void GameDataFile::setGotShine(const GameDataFile::HintInfo* hintInfo) {}

bool GameDataFile::isEnableOpenMoonRock(s32 worldId) const {}

bool GameDataFile::tryWriteByByaml(al::ByamlWriter* writer) {}
