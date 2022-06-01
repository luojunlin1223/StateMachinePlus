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
            activeComponent= i->second->GetDestinationState();
        }
    }
}

std::string StateMachine::Print(int index) {
    std::string active;
    for(auto & it : ComponentContainer)
    {
        if(it.second==activeComponent)
        {
            active=it.first;
            break;
        }
    }
    std::string buffer("[StateMachine]");
   buffer+="<"+active+">\n";
    for(auto i:ComponentContainer)
    {
        for (int j = 0; j < index; ++j) {
            buffer+="    ";
        }
        buffer+="("+i.first+")"+i.second->Print(index+1);
    }
    return buffer;
}

void StateMachine::AddTransition(StateTransition *t) {
    allTransitions.insert(std::make_pair(t->GetSourceState(), t));
}

void StateMachine::SetActiveComponent(AbstractComponent *a) {
    activeComponent=a;
}

