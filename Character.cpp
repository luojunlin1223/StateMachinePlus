//
// Created by 16499 on 2022/5/28.
//

#include "Character.h"
#include "EventSystem.h"
Character::Character()
    :stateMachine(nullptr),
    health(100),
    target(nullptr),
    pet(nullptr),
    lastCommons(Commands::NONE)
{
    init();
}



void Character::init() {
    auto attack=new State([this](float dt)->void{ return AttackUpdate(dt);});
    auto prepare=new State([this](float dt)->void{ return PrepareUpdate(dt);});

    auto actions=new StateMachine("prepare",prepare);
    actions->AddComponent("attack", attack);
    actions->AddTransition(new StateTransition(attack,prepare,
                                               [this](EVENT* event)->bool{return AttackToPrepare();},""));
    actions->AddTransition(new StateTransition(prepare,attack,
                                               [this](EVENT* event)->bool{return PrepareToAttack();},""));

    auto move=new State([this](float dt)->void{ return MoveUpdate(dt);});
    auto stand=new State([this](float dt)->void{ return StandUpdate(dt);});
    auto movement= new StateMachine("stand", stand);
    movement->AddComponent("move", move);
    movement->AddTransition(new StateTransition(move,stand,
                                               [this](EVENT* event)->bool{return MoveToStand();},""));
    movement->AddTransition(new StateTransition(stand,move,
                                                [this](EVENT* event)->bool{return StandToMove();},""));

    auto model=new StateMachinePlus;
    model->AddComponent("actions", actions);
    model->AddComponent("movement", movement);

    auto alive=new StateMachinePlus;
    alive->AddComponent("model", model);


    auto dead=new State([this](float dt)->void{ return DeadUpdate(dt);});
    stateMachine=std::make_shared<StateMachine>("alive",alive);
    stateMachine->AddComponent("dead",dead);
    stateMachine->AddTransition(new StateTransition(alive,dead,
                                             [this](EVENT* event)->bool{return AliveToDead();},""));

}

void Character::Update(float dt) {
    stateMachine->Update(dt);
}

bool Character::AttackToPrepare() {
    return target->health==0&&lastCommons==Commands::STOP;
}

bool Character::PrepareToAttack() {
    if(!target)return false;
    return target->health>0&&lastCommons==Commands::ATTACK;
}

bool Character::AliveToDead() {
    return health==0;
}

bool Character::MoveToStand() {
    return lastCommons==Commands::STOP;
}

bool Character::StandToMove() {
    return lastCommons==Commands::MOVE;
}

void Character::AttackUpdate(float dt) {
    if(!target)return;
    target->GetDamage(1);
}

void Character::PrepareUpdate(float dt) {

}

void Character::MoveUpdate(float dt) {

}

void Character::StandUpdate(float dt) {

}

void Character::DeadUpdate(float dt) {

}


void Character::GetDamage(int damage) {
    health=health-damage<=0?0:health-damage;
    EventSystem::Get().PushEvent("GetDamage",1,std::to_string(id).c_str());
}

std::string Character::Print() {
    std::string buffer;
    buffer+="Health:"+std::to_string(health)+"\n";
    buffer+=stateMachine->Print(0);
    return buffer;
}

Character::~Character() = default;

