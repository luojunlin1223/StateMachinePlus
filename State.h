//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_STATE_H
#define STATEMACHINEPLUS_STATE_H
#include <functional>
#include "AbstractComponent.h"
typedef std::function<void(float)> StateUpdateFunction;
class State:public AbstractComponent
{
public:
    explicit State(StateUpdateFunction updateFunction) {
        func = std::move(updateFunction);
    }
    ~State()override = default;
    void Update(float dt) override {
        if (func != nullptr)
            func(dt);
    }
    std::string Print(int index)override;
protected:
    StateUpdateFunction func;
};


#endif //STATEMACHINEPLUS_STATE_H
