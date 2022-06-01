//
// Created by 16499 on 2022/5/27.
//

#include "AbstractStateMachine.h"
#include "State.h"
void AbstractStateMachine::AddComponent(const std::string& name, AbstractComponent* c) {
    ComponentContainer.insert(std::make_pair(name, c));
}
AbstractComponent* AbstractStateMachine::GetComponent(const std::string& name) {
    auto temp=ComponentContainer.find(name);
    if(temp!=ComponentContainer.end())return temp->second;
    for (const auto& i: ComponentContainer) {
        if(dynamic_cast<State*>(i.second)== nullptr){
            auto sub=(AbstractStateMachine*)(i.second);
            AbstractComponent* result=sub->GetComponent(name);
            if(result!= nullptr)return result;
        }
    }
    return nullptr;
}
