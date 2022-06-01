//
// Created by 16499 on 2022/5/28.
//

#ifndef STATEMACHINEPLUS_CHARACTER_H
#define STATEMACHINEPLUS_CHARACTER_H

#include <memory>
#include "StateMachine.h"
#include "State.h"
#include "StateMachinePlus.h"
#include "StateTransition.h"
enum class Commands{
    NONE,
    STOP,
    ATTACK,
    MOVE,
    TAUNT
};
class Pet;
class Character {
public:
    Character();
    virtual ~Character();
    virtual void Update(float dt);
    void GetDamage(int damage);
    std::string  Print();
    std::shared_ptr<StateMachine> GetStateMachine(){return stateMachine;}
    int id;
    int health;
    Character* target;
    Pet* pet;
    Commands lastCommons;
protected:
    std::shared_ptr<StateMachine> stateMachine;
private:
    void init();
    virtual bool AttackToPrepare();
    virtual bool PrepareToAttack();
    virtual bool AliveToDead();
    virtual bool MoveToStand();
    virtual bool StandToMove();

    virtual void AttackUpdate(float dt);
    virtual void PrepareUpdate(float dt);
    virtual void MoveUpdate(float dt);
    virtual void StandUpdate(float dt);
    virtual void DeadUpdate(float dt);
};


#endif //STATEMACHINEPLUS_CHARACTER_H
