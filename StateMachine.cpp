//
// Created by 16499 on 2022/5/27.
//

#include "StateMachine.h"
#include "State.h"
#include "StateTransition.h"
void StateMachine::Update(float dt) {
    if(activeComponent==nullptr)return;
    activeComponent->Update(dt);
    //Get the transition set starting from this state node;
    std::pair<TransitionIterator, TransitionIterator> range = allTransitions.equal_range(activeComponent);

    for (auto& i = range.first; i != range.second; ++i)
    {
        if (i->second->CanTransition())
        {
            activeComponent = i->second->GetDestinationState();
        }
    }



}

std::string StateMachine::Print() {
    return "";
}

void StateMachine::AddTransition(StateTransition *t) {
    allTransitions.insert(std::make_pair(t->GetSourceState(), t));
}

