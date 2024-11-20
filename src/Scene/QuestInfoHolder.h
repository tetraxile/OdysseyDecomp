#pragma once

#include "Library/Scene/ISceneObj.h"
#include "Library/HostIO/HioNode.h"

namespace al {
class ActorInitInfo;
class PlacementInfo;
class IUseSceneObjHolder;
class SceneObjHolder;
template <s32 N> class StringTmp;
}  // namespace al

class QuestInfo;

class QuestInfoHolder : public al::ISceneObj, public al::HioNode {
public:
    QuestInfoHolder(s32);
    void clearAll();
    void finalizeForScene();
    void initAfterPlacementSceneObj(const al::ActorInitInfo&);
    void initAfterPlacementQuestObj(s32);
    void updateActiveList(s32);
    void clearMainQuest();
    void initSceneObjHolder(al::SceneObjHolder*);
    void registerQuestInfo(const QuestInfo*);
    void validateQuest(const QuestInfo*);
    void* tryFindQuest(const QuestInfo*) const;
    void invalidateQuest(const QuestInfo*);
    s32 getQuestNum(s32) const;
    al::StringTmp<128> getActiveQuestLabel() const;
    al::StringTmp<128> getActiveQuestStageName(const al::IUseSceneObjHolder*) const;
    bool isActiveQuest(const QuestInfo*) const;
    void* tryFindQuest(const al::PlacementInfo&, al::SceneObjHolder*) const;
    const char* getSceneObjName() const override;
    ~QuestInfoHolder();

private:

};

namespace rs {
s32 getActiveQuestNum(const al::IUseSceneObjHolder*);
s32 getActiveQuestNo(const al::IUseSceneObjHolder*);
const char* getActiveQuestLabel(const al::IUseSceneObjHolder*);
}  // namespace rs
