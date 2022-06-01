//
// Created by 16499 on 2022/5/30.
//

#ifndef STATEMACHINEPLUS_MONSTER_H
#define STATEMACHINEPLUS_MONSTER_H

#include "Character.h"
class Monster :public Character{
public:
    Monster();
    ~Monster() override;
    std::map<Character*,int> ThreatMap;
private:
    void AttackUpdate(float dt) override;
    //怪物转换目标的时候认为是一个事件 当这个目标是谁就 出发谁的仇恨系统状态的转换、、
};


#endif //STATEMACHINEPLUS_MONSTER_H
