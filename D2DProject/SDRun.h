#pragma once
#include "DemoApp.h"
#include "IPlayerState.h"
#include "SPlayer.h"

// �⺻ ���� (�ٸ� ���ӿ����� Idle�� ���� �ִ�) �� ��Ÿ��
class SDRun : public IPlayerState, public IAnimationProcesser
{
	InputManager KeyManager;
public:
	SDRun(FiniteStateMachine* pOwner, std::string Name)
		:IPlayerState(pOwner, Name)
	{}
	virtual ~SDRun() {}

	void Enter();
	void Update();
	void Exit();
	virtual void OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName);
};