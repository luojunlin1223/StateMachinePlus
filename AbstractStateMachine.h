//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_ABSTRACTSTATEMACHINE_H
#define STATEMACHINEPLUS_ABSTRACTSTATEMACHINE_H
#include <map>
#include <string>
#include <functional>
#include "AbstractComponent.h"
class AbstractStateMachine{
public:
    AbstractStateMachine()=default;
    virtual ~AbstractStateMachine()=default;
    void AddComponent(const std::string&,AbstractComponent*);
    AbstractComponent* GetComponent(const std::string&);
protected:
    std::map<std::string,AbstractComponent*> ComponentContainer;
   /* std::multimap<std::string,std::function<bool()>> conditionFuncContainer;
    std::multimap<std::string,std::function<void()>> handlerFuncContainer; for event */
};


#endif //STATEMACHINEPLUS_ABSTRACTSTATEMACHINE_H
