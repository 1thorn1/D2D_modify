#pragma once
#include "DemoApp.h"
#include "IPlayerState.h"
#include "SPlayer.h"

// �����Q�� ������ �� �� ���
class Jump : public IPlayerState, public IAnimationProcesser
{
	InputManager KeyManager;
	bool isJumping;

public:
	Jump(FiniteStateMachine* pOwner, std::string Name)
		:IPlayerState(pOwner, Name)
	{}
	virtual ~Jump() {}
	virtual void Initialize();

	void Enter();
	void Update();
	void Exit();

	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};
