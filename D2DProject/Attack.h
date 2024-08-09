#pragma once
#include "IPlayerState.h"
#include "SPlayer.h"

// ���� ���� ĥ �� ��Ÿ���� ����

class Attack : public IPlayerState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	Attack(FiniteStateMachine* pOwner, std::string Name)
		:IPlayerState(pOwner, Name)
	{}
	virtual ~Attack() {}

	void Enter();
	void Update();
	void Exit();

	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};

