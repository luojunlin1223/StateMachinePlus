//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_ABSTRACTSTATEMACHINE_H
#define STATEMACHINEPLUS_ABSTRACTSTATEMACHINE_H
#include <map>
#include <string>
#include <functional>
#include "AbstractComponent.h"
using ContainerIterator = std::map<std::string,AbstractComponent*>::iterator;
class AbstractStateMachine:public AbstractComponent{
public:
    AbstractStateMachine()=default;
    ~AbstractStateMachine() override =default;
    void AddComponent(const std::string&,AbstractComponent*);
    AbstractComponent *GetComponent(const std::string &);
protected:
    std::map<std::string,AbstractComponent*> ComponentContainer;
};


#endif //STATEMACHINEPLUS_ABSTRACTSTATEMACHINE_H
