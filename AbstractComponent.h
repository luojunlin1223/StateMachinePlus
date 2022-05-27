//
// Created by 16499 on 2022/5/27.
//

#ifndef STATEMACHINEPLUS_ABSTRACTCOMPONENT_H
#define STATEMACHINEPLUS_ABSTRACTCOMPONENT_H
#include <string>
class AbstractComponent {
public:
    AbstractComponent()=default;
    virtual ~AbstractComponent()=default;
    virtual void Update(float dt);
    virtual std::string Print();
};


#endif //STATEMACHINEPLUS_ABSTRACTCOMPONENT_H
