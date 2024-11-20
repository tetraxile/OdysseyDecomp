#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>

namespace al {
class PlacementInfo;
class LiveActor;
}

class GameDataHolder;

class ChangeStageInfo {
public:
    enum class SubScenarioType {

    };

    ChangeStageInfo(const GameDataHolder* dataHolder, const al::PlacementInfo&);
    void init(const al::PlacementInfo&, const GameDataHolder*);
    ChangeStageInfo(const GameDataHolder* dataHolder, const al::PlacementInfo&, const char* label, const char* stageName, bool isReturnPrevStage, s32 scenarioNo, SubScenarioType subScenarioType);
    void findScenarioNoByList(const GameDataHolder* dataHolder);
    ChangeStageInfo(const GameDataHolder* dataHolder, const char* label, const char* stageName, bool isReturnPrevStage, s32 scenarioNo, SubScenarioType subScenarioType);
    void init();
    void copy(const ChangeStageInfo& src);
    bool isSubScenarioTypeLifeRecover();
    bool isSubScenarioTypeResetMiniGame();
    void setWipeType(const char* wipeName);
    void calcTrans(sead::Vector3f* outTrans, const al::PlacementInfo&);

private:
    sead::FixedSafeString<128> mLabel;
    sead::FixedSafeString<128> mStageName;
    sead::FixedSafeString<128> field_130;
    bool mIsReturnPrevStage;
    s32 mScenarioNo;
    SubScenarioType mSubScenarioType;
    sead::FixedSafeString<128> mWipeType;
    s32 mHintPriority;
};

static_assert(sizeof(ChangeStageInfo) == 0x278);

namespace rs {
ChangeStageInfo* createChangeStageInfo(const al::LiveActor* actor, const al::PlacementInfo&);
ChangeStageInfo* createChangeStageInfo(const al::LiveActor* actor, const al::PlacementInfo&, const char*, const char*, bool, s32, ChangeStageInfo::SubScenarioType);
ChangeStageInfo* createChangeStageInfo(const al::LiveActor* actor, const char*, const char*, bool, s32, ChangeStageInfo::SubScenarioType);
}
