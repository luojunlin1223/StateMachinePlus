//
// Created by 16499 on 2022/5/27.
//

#include "EventSystem.h"

void EventSystem::Update(float dt) {
   for(auto i:conditionFuncContainer)
   {
       if((i.second)(dt))
       {
           eventQueue.emplace_back(i.first);
           break;
       }
   }

    for (auto & event : eventQueue)
    {
        std::pair<HandlerFuncIterator,HandlerFuncIterator> range = handlerFuncContainer.equal_range(event);
        for (auto& i = range.first; i != range.second; ++i)
        {
            (i->second)(dt);
        }
    }
    eventQueue.clear();
}

std::string EventSystem::Print() {
    return "";
}

void EventSystem::RegisterEventHandle(const std::string& event, const std::function<void(float)>& func) {
    handlerFuncContainer.insert(std::make_pair(event,func));
}

EventSystem &EventSystem::Get() {
    static EventSystem instance;
    return  instance;
}

void EventSystem::RegisterEventTrigger(const std::string &event, const std::function<bool(float)> &func) {
    conditionFuncContainer.insert(std::make_pair(event,func));
}

bool EventSystem::HasHappened(const std::string & name) {
    EventQueueIterator iterator;
    iterator = std::find(eventQueue.begin(),eventQueue.end(), name);
    return iterator != eventQueue.end();
}

