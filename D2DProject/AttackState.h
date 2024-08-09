#pragma once
#include "DemoApp.h"

class AttackState : public FSMState
{
public:

	AttackState(FiniteStateMachine* pOwner, std::string Name)
		:FSMState(pOwner, Name)
	{}
	virtual ~AttackState() {}

	virtual void Enter();
	virtual void Update();
	virtual void Exit();
};

