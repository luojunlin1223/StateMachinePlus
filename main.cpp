#include <iostream>
#include "StateMachine.h"
#include "StateMachinePlus.h"
#include "State.h"
#include "StateTransition.h"
int main() {

    State attack([](float dt)->void{ printf("im attack\n");});
    State prepare([](float dt)->void{ printf("im prepare\n");});

    StateMachine sm1("state attack",&attack);
    sm1.AddComponent("state prepare",&prepare);
    sm1.AddTransition(new StateTransition(&attack,&prepare,[]()->bool{return true;}));


    State move([](float dt)->void{ printf("im move\n");});
    State stand([](float dt)->void{ printf("im stand\n");});
    StateMachine sm2("state move",&move);
    sm2.AddComponent("state stand",&stand);
    sm2.AddTransition(new StateTransition(&move,&stand,[]()->bool{return true;}));

    StateMachinePlus stateMachinePlus1;
    stateMachinePlus1.AddComponent("sm1",&sm1);
    stateMachinePlus1.AddComponent("sm2",&sm2);

    State overThreat([](float dt)->void{ printf("im overThreat\n");});
    State underThreat([](float dt)->void{ printf("im underThreat\n");});
    StateMachine sm3("state overThreat",&overThreat);
    sm3.AddComponent("state underThreat",&underThreat);

    StateMachinePlus stateMachinePlus2;
    stateMachinePlus2.AddComponent("left",&stateMachinePlus1);
    stateMachinePlus2.AddComponent("right",&sm3);

    State dead([](float dt)->void{ printf("im dead\n");});
    StateMachine final("state dead",&dead);
    final.AddComponent("state alive",&stateMachinePlus2);
    final.AddTransition(new StateTransition(&dead,&stateMachinePlus2,[]()->bool{return true;}));

    final.Update(0.1f);
    final.Update(0.1f);
    return 0;
}
