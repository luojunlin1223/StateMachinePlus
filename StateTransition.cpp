//
// Created by 16499 on 2022/5/27.
//

#include "StateTransition.h"
bool StateTransition::CanTransition() const
{
    auto event=EventSystem::Get().HasHappened(trigger);
    if (trigger.empty()||event) return transitionFunction(event);
    return false;
}
