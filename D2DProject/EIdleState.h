#pragma once
#include "IEnemyState.h"
#include "Enemy.h"
#include "Player.h"

class EIdleState : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	EIdleState(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~EIdleState() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};

