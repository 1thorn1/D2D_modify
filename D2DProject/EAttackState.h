#pragma once
#include "IEnemyState.h"
#include "Enemy.h"
#include "Player.h"

class EAttackState : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	EAttackState(FiniteStateMachine* pOwner, std::string Name)
		:IEnemyState(pOwner, Name)
	{}
	virtual ~EAttackState() {}

	void Enter();
	void Update();
	void Exit();

	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};

