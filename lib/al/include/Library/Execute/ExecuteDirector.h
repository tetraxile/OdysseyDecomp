#pragma once

namespace al {
class ExecuteRequestKeeper;
class ExecuteTableHolderDraw;
class ExecuteTableHolderUpdate;
class ExecuteSystemInitInfo;
class FunctorBase;
class IUseExecutor;
class LayoutActor;
class LiveActor;

class ExecuteDirector {
public:
    ExecuteDirector(int count);
    virtual ~ExecuteDirector();
    void init(const ExecuteSystemInitInfo&);
    void registerActorUpdate(LiveActor*, const char*);
    void registerActorDraw(LiveActor*, const char*);
    void registerActorModelDraw(LiveActor*, const char*);
    void registerLayoutUpdate(LayoutActor*, const char*);
    void registerLayoutDraw(LayoutActor*, const char*);
    void registerUser(IUseExecutor*, const char*);
    void registerFunctor(const FunctorBase&, const char*);
    void registerFunctorDraw(const FunctorBase&, const char*);
    void createExecutorListTable();
    void execute(const char*) const;
    void executeList(const char*, const char*) const;
    void draw(const char*) const;
    void drawList(const char*, const char*) const;
    bool isActiveDraw(const char*) const;

private:
    int mRequestCount = 0;
    int mUpdateTableCount = 0;
    ExecuteTableHolderUpdate** mUpdateTables = nullptr;
    int mDrawTableCount = 0;
    ExecuteTableHolderDraw** mDrawTables = nullptr;
    ExecuteRequestKeeper* mRequestKeeper = nullptr;
};
}