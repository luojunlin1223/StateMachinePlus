//
// Created by 16499 on 2022/5/28.
//

#ifndef STATEMACHINEPLUS_PET_H
#define STATEMACHINEPLUS_PET_H

#include "Player.h"
enum class ControlModelType{
    PASSIVE,
    ASSIST,
    PROTECT
};
class Pet: public Player{
public:
    Pet(Character*);
    ~Pet() override;
    ControlModelType model;
    Character* owner;
private:
    void init();

    bool AttackToPrepare() override;

    bool PrepareToAttack() override;
    virtual bool AttackToTaunt();
    virtual bool TauntToAttack();

    bool MoveToStand() override;

    bool StandToMove() override;

};


#endif //STATEMACHINEPLUS_PET_H
