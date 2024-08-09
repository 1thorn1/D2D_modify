#pragma once
#include "DemoApp.h"
#include "Player.h"

class IdleState 
	: public FSMState
{
	InputManager KeyManager;
public:
	IdleState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~IdleState() {}

	void Enter();
	void Update();
	void Exit();

};