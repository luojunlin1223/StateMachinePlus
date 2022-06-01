//
// Created by 16499 on 2022/5/30.
//

#include "Monster.h"
#include "EventSystem.h"
Monster::Monster() = default;

Monster::~Monster() = default;
bool cmp_value(const std::pair<Character*, int> left,const std::pair<Character*,int> right)
{
    return left.second < right.second;
}
void Monster::AttackUpdate(float dt) {
    auto i= max_element(ThreatMap.begin(),ThreatMap.end(),cmp_value);
    target=i->first;
    target->GetDamage(1);
    EventSystem::Get().PushEvent("ThreatChanged",1,std::to_string(target->id).c_str());
}
