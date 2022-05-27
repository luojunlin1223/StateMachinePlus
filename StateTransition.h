//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_STATETRANSITION_H
#define STATEMACHINEPLUS_STATETRANSITION_H

#include <functional>
#include <string>
#include "AbstractComponent.h"
class State;
typedef std::function<bool()> StateTransitionFunction;
class StateTransition
{
public:
    StateTransition(AbstractComponent* source, AbstractComponent* dest,StateTransitionFunction f,std::string trigger="") {
        sourceState = source;
        destinationState = dest;
        transitionFunction = std::move(f);
        trigger = std::move(trigger);
    }
    bool CanTransition() const;
    AbstractComponent* GetDestinationState() const { return destinationState; }
    AbstractComponent* GetSourceState() const { return sourceState; }
protected:
    AbstractComponent* sourceState;
    AbstractComponent* destinationState;
    StateTransitionFunction transitionFunction;
    std::string trigger;
};


#endif //STATEMACHINEPLUS_STATETRANSITION_H
