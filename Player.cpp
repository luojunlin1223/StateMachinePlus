//
// Created by 16499 on 2022/5/28.
//

#include "Player.h"
#include "EventSystem.h"
Player::Player() {
    auto overThreat=new State([this](float dt)->void{});
    auto underThreat=new State([this](float dt)->void{});
    auto ThreatSystem=new StateMachine("underThreat", underThreat);
    ThreatSystem->AddComponent("overThreat", overThreat);
    ThreatSystem->AddTransition(new StateTransition(overThreat,underThreat,[this](EVENT* event)->bool{
            std::string _id=event->vArg[0];
            return std::to_string(id)!=_id;
        },"ThreatChanged"));
    ThreatSystem->AddTransition(new StateTransition(underThreat,overThreat,[this](EVENT* event)->bool{
            std::string _id=event->vArg[0];
            return std::to_string(id)==_id;
        },"ThreatChanged"));

    auto alive=(StateMachinePlus*)stateMachine->GetComponent("alive");
    alive->AddComponent("ThreatSystem", ThreatSystem);

}

Player::~Player()=default;
