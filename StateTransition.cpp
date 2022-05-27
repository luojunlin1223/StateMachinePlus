//
// Created by 16499 on 2022/5/27.
//

#include "StateTransition.h"
#include "EventSystem.h"
bool StateTransition::CanTransition() const
{
    if (trigger.empty()||EventSystem::Get().HasHappened(trigger))
        return transitionFunction();
    else
        return false;
}
