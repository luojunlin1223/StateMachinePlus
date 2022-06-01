//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_EVENTSYSTEM_H
#define STATEMACHINEPLUS_EVENTSYSTEM_H
#include "AbstractStateMachine.h"
#include <list>
#include <vector>
struct EVENT;
struct EVENT_DEFINE{
    std::string name;
    std::list<std::function<void(EVENT*)>> listFunc;
};
struct EVENT{
    EVENT_DEFINE* pEventDef;
    std::vector<std::string> vArg;
};
using EventDefContainer = std::map<std::string,EVENT_DEFINE*>;
using EventDefContainerIterator = EventDefContainer::iterator;
using EventQueueIterator=std::list<EVENT*>::iterator;
class EventSystem :public AbstractStateMachine{
public:
    EventSystem(){init();}
    ~EventSystem() override =default;
    void Update(float dt) override;
    std::string Print(int index) override;
    void RegisterEventHandler(const std::string&, const std::function<void(EVENT*)>&);
    void PushEvent(const std::string&,int n,...);
    static EventSystem& Get();
    EVENT* HasHappened(const std::string&);
private:
    void init();
    EventDefContainer eventDefContainer;
    std::list<EVENT*> eventQueue;
    std::vector<std::string> eventRecords;
};


#endif //STATEMACHINEPLUS_EVENTSYSTEM_H
