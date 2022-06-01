cmake_minimum_required(VERSION 3.22)
project(StateMachinePlus)

set(CMAKE_CXX_STANDARD 20)

add_executable(StateMachinePlus main.cpp AbstractStateMachine.cpp AbstractStateMachine.h State.cpp State.h StateTransition.cpp StateTransition.h StateMachine.cpp StateMachine.h EventSystem.cpp EventSystem.h StateMachinePlus.cpp StateMachinePlus.h AbstractComponent.cpp AbstractComponent.h Character.cpp Character.h Player.cpp Player.h Pet.cpp Pet.h Monster.cpp Monster.h)
