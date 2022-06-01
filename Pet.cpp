//
// Created by 16499 on 2022/5/28.
//

#include "Pet.h"

Pet::Pet(Character* _owner)
    :model(ControlModelType::PASSIVE),
    owner(_owner)
{
    init();
}

void Pet::init() {
    auto actions=(StateMachine*)stateMachine->GetComponent("actions");
    auto taunt=new State([](float dt)->void{ printf("im taunt\n");});
    auto attack=stateMachine->GetComponent("attack");
    actions->AddComponent("taunt",taunt);
    actions->AddTransition(new StateTransition(attack,taunt,[this](EVENT* event)->bool{return AttackToTaunt();},""));
    actions->AddTransition(new StateTransition(taunt,attack,[this](EVENT* event)->bool{return TauntToAttack();},""));
}

bool Pet::AttackToPrepare() {
    if(model==ControlModelType::PASSIVE)return lastCommons==Commands::STOP;
    if(model==ControlModelType::ASSIST)return owner->lastCommons==Commands::STOP;
    if(model==ControlModelType::PROTECT)return owner->lastCommons==Commands::STOP;
}

bool Pet::PrepareToAttack() {
    if(!target)return false;
    if(model==ControlModelType::PASSIVE)return target->health>0&&lastCommons==Commands::ATTACK;;
    if(model==ControlModelType::ASSIST)return owner->lastCommons==Commands::ATTACK;
    if(model==ControlModelType::PROTECT)return false;
}

bool Pet::AttackToTaunt() {
    return lastCommons==Commands::TAUNT&&target->health!=0;
}

bool Pet::TauntToAttack() {
    return false;
}

bool Pet::MoveToStand() {
    return owner->lastCommons!=Commands::MOVE;
}

bool Pet::StandToMove() {
    return owner->lastCommons==Commands::MOVE;
}

Pet::~Pet() = default;
