//
// Created by 16499 on 2022/5/27.
//

#include <cstdarg>
#include "EventSystem.h"
extern EVENT_DEFINE g_Events[]=
{
        {"test"},
        {"test2"},
        {"ThreatChanged"},
        {"GetDamage"}
};
void EventSystem::Update(float dt) {

    for (auto & event : eventQueue)
    {
        for(auto func=event->pEventDef->listFunc.begin();func!=event->pEventDef->listFunc.end();func++)
        {
                (*func)(event);
        }
    }
    eventQueue.clear();
}

std::string EventSystem::Print(int index) {
    std::string buffer;
    buffer+="Event Records:";
    for(auto i:eventRecords){
        buffer+="["+i+"]";
    }
    return buffer;
}

void EventSystem::RegisterEventHandler(const std::string& event, const std::function<void(EVENT* pEvent)>& func) {
    eventDefContainer[event]->listFunc.emplace_back(func);
}

EventSystem &EventSystem::Get() {
    static EventSystem instance;
    return  instance;
}

EVENT* EventSystem::HasHappened(const std::string & name) {
   for(auto event:eventQueue){
       if(event->pEventDef->name==name)
           return event;
   }
   return nullptr;
}

void EventSystem::PushEvent(const std::string & name, int n, ...) {
    EVENT* event=new EVENT;
    event->pEventDef=eventDefContainer[name];
    va_list args;
    va_start(args, n);
    for (int i = 0; i <n; ++i) {
        event->vArg.emplace_back(va_arg(args,char*));
    }
    va_end(args);

    eventQueue.emplace_back(event);
    eventRecords.emplace_back(event->pEventDef->name);
}

void EventSystem::init() {
    int nEventNum = sizeof(g_Events) / sizeof(EVENT_DEFINE);

    for (int i = 0; i < nEventNum; i++)
    {
        eventDefContainer[g_Events[i].name] = &(g_Events[i]);
    }
}

