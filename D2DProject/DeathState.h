#pragma once
#include "DemoApp.h"

class DeathState : public FSMState
{
public:
	DeathState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~DeathState() {}

	void Enter();
	void Update();
	void Exit();
};

