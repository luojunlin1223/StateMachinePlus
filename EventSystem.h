//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_EVENTSYSTEM_H
#define STATEMACHINEPLUS_EVENTSYSTEM_H
#include "AbstractStateMachine.h"
#include <list>
using HandlerFuncContainer = std::multimap<std::string,std::function<void(float)>>;
using HandlerFuncIterator = HandlerFuncContainer::iterator;
using ConditionFuncContainer = std::multimap<std::string,std::function<bool(float)>> ;
using ConditionFuncIterator = ConditionFuncContainer::iterator;
using EventQueueIterator=std::list<std::string>::iterator;

class EventSystem :public AbstractStateMachine,AbstractComponent{
public:
    EventSystem()=default;
    ~EventSystem() override =default;
    void Update(float dt) override;
    std::string Print() override;
    void RegisterEventHandle(const std::string&, const std::function<void(float)>&);
    void RegisterEventTrigger(const std::string&, const std::function<bool(float)>&);
    static EventSystem& Get();
    bool HasHappened(const std::string&);
private:
    ConditionFuncContainer conditionFuncContainer;
    HandlerFuncContainer handlerFuncContainer;
    std::list<std::string> eventQueue;
};


#endif //STATEMACHINEPLUS_EVENTSYSTEM_H
