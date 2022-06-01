#include "Player.h"
#include "Pet.h"
#include "Monster.h"
#include "EventSystem.h"
void TestCommands();
void TestEventSystem();
void TestThreatSystem();
void TestPetModel();
EventSystem eventSystem;
auto player=new Player;
auto monster=new Monster;
auto pet=new Pet(player);

int main() {
    monster->ThreatMap.insert(std::make_pair(player, 10));
    monster->ThreatMap.insert(std::make_pair(pet, 5));
    player->target=monster;
    player->id=0;
    monster->id=1;
    pet->id=2;

    TestCommands();
    TestEventSystem();
    TestThreatSystem();
    TestPetModel();
    printf("%s",EventSystem::Get().Print(0).c_str());
    return 0;
}
void TestCommands()
{
    printf("TestCommands:\n");
    player->lastCommons=Commands::ATTACK;
    player->Update(0.1f);
    player->lastCommons=Commands::MOVE;
    player->Update(0.1f);

    pet->lastCommons=Commands::MOVE;
    pet->Update(0.1f);

    monster->Update(0.1f);
    EventSystem::Get().Update(0.1f);
    printf("Player:%s", player->Print().c_str());
    printf("Pet:%s",pet->Print().c_str());
    printf("Monster:%s", monster->Print().c_str());
    printf("\n\n\n");
}
void TestEventSystem(){
    printf("TestEventSystem:\n");
    EventSystem::Get().RegisterEventHandler("test",[](EVENT* event)->void{
        printf("arg0:%s\n",event->vArg[0].c_str());
        printf("arg1:%s\n",event->vArg[1].c_str());
    });

    EventSystem::Get().RegisterEventHandler("test",[](EVENT* event)->void{
        printf("another arg0:%s\n",event->vArg[0].c_str());
        printf("another arg1:%s\n",event->vArg[1].c_str());
    });

    EventSystem::Get().PushEvent("test",2,"first","last");
    EventSystem::Get().PushEvent("test",2,"first1","last1");
    EventSystem::Get().Update(0.1f);
    printf("\n\n\n");
}
void TestThreatSystem(){
    printf("TestThreatSystem:\n");
    monster->target= player;

    monster->lastCommons=Commands::ATTACK;
    monster->Update(0.1f);
    monster->Update(0.1f);
    player->Update(0.1f);
    pet->Update(0.1f);
    EventSystem::Get().Update(0.1f);

    printf("Player:%s", player->Print().c_str());
    printf("Pet:%s",pet->Print().c_str());
    printf("Monster:%s", monster->Print().c_str());

    monster->ThreatMap[pet]=15;
    monster->Update(0.1f);
    player->Update(0.1f);
    pet->Update(0.1f);
    EventSystem::Get().Update(0.1f);
    printf("Player:%s", player->Print().c_str());
    printf("Pet:%s",pet->Print().c_str());
    printf("Monster:%s", monster->Print().c_str());
    printf("\n\n\n");
}
void TestPetModel(){
    printf("TestPetModel:\n");
    monster->lastCommons=Commands::ATTACK;
    monster->ThreatMap[pet]=0;
    monster->Update(0.1f);
    player->Update(0.1f);
    pet->Update(0.1f);
    EventSystem::Get().Update(0.1f);

    printf("Player:%s", player->Print().c_str());
    printf("Pet:%s",pet->Print().c_str());
    printf("Monster:%s", monster->Print().c_str());

    EventSystem::Get().RegisterEventHandler("GetDamage",[&](EVENT* pEvent)->void{
        if(pet->model!=ControlModelType::PROTECT)return;
        std::string _id=pEvent->vArg[0];
        std::shared_ptr<StateMachine> stateMachine=pet->GetStateMachine();
        auto actions=(StateMachine*)stateMachine->GetComponent("actions");
        auto attack=stateMachine->GetComponent("attack");
        if(std::to_string(pet->owner->id)==_id)
        {
            actions->SetActiveComponent(attack);
        }
    });
    pet->model=ControlModelType::PROTECT;
    monster->Update(0.1f);
    player->Update(0.1f);
    pet->Update(0.1f);
    EventSystem::Get().Update(0.1f);

    printf("Player:%s", player->Print().c_str());
    printf("Pet:%s",pet->Print().c_str());
    printf("Monster:%s", monster->Print().c_str());

    printf("\n\n\n");
}