//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_STATEMACHINE_H
#define STATEMACHINEPLUS_STATEMACHINE_H
#include <map>
#include "AbstractStateMachine.h"
#include "AbstractComponent.h"
class StateTransition;
using TransitionContainer = std::multimap<AbstractComponent*, StateTransition*>;
using TransitionIterator = TransitionContainer::iterator;
class StateMachine: public AbstractStateMachine,public AbstractComponent{
public:
    explicit StateMachine(const std::string& name,AbstractComponent* defaultComponent)
    :activeComponent(defaultComponent){ AddComponent(name,defaultComponent);}

    ~StateMachine() override =default;
    void Update(float dt) override;
    std::string Print() override;

    void AddTransition(StateTransition* t);
protected:
    AbstractComponent* activeComponent;
    TransitionContainer allTransitions;
};


#endif //STATEMACHINEPLUS_STATEMACHINE_H
