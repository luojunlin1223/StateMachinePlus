//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_STATEMACHINEPLUS_H
#define STATEMACHINEPLUS_STATEMACHINEPLUS_H
#include "AbstractStateMachine.h"
#include "AbstractComponent.h"
class StateMachinePlus: public AbstractStateMachine,public AbstractComponent{
public:
    StateMachinePlus()=default;
    ~StateMachinePlus() override =default;
    void Update(float dt) override;
    std::string Print() override;
};


#endif //STATEMACHINEPLUS_STATEMACHINEPLUS_H
