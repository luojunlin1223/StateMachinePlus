//
// Created by 16499 on 2022/5/27.
//

#include "AbstractStateMachine.h"

void AbstractStateMachine::AddComponent(const std::string& name, AbstractComponent* c) {
    ComponentContainer.insert(std::make_pair(name, c));
}

AbstractComponent* AbstractStateMachine::GetComponent(const std::string& name) {
    auto temp=ComponentContainer.find(name);
    return temp->second;
}


