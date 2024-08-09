#pragma once
#include "IEnemyState.h"
#include "Player.h"
#include "Enemy.h"
#include "../Engine/MathHelper.h"

class EMoveState : public IEnemyState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	EMoveState(FiniteStateMachine* pOwner, std::string Name)
		: IEnemyState(pOwner, Name)
	{}
	virtual ~EMoveState() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};

