//
// Created by 16499 on 2022/5/27.
//

#include "StateMachinePlus.h"
#include "StateMachine.h"
void StateMachinePlus::Update(float dt) {
    for(const auto& i:ComponentContainer)
    {
        auto subStateMachine=i.second;
        if(subStateMachine)
            subStateMachine->Update(dt);
    }
}

std::string StateMachinePlus::Print(int index) {
    std::string buffer("[StateMachinePlus]\n");
    for(auto i:ComponentContainer)
    {
        for (int j = 0; j < index; ++j) {
            buffer+="    ";
        }
        buffer+="("+i.first+")"+i.second->Print(index+1);
    }
    return buffer;
}
