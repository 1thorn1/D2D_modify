#pragma once
#include "IPlayerState.h"
#include "SPlayer.h"

// �⺻ ���� (�ٸ� ���ӿ����� Idle�� ���� �ִ�) �� ��Ÿ��
class Idle : public IPlayerState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	Idle(FiniteStateMachine* pOwner, std::string Name)
		:IPlayerState(pOwner, Name)
	{}
	virtual ~Idle() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};