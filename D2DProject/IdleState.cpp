#include "IdleState.h"

void IdleState::Enter()
{
	AnimationScene* PIdleAni;
	PIdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	PIdleAni->LoadAnimationAsset(L"CSV/KenIdle.txt");
	PIdleAni->SetAnimation(1, 0);
	//m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
}

void IdleState::Update()
{
	 /*Ư�� Ű ������ �� Ư�� Walk ��������Ʈ�� �۵��ϰԲ�
	 �÷��̾� �ִϸ��̼��� ��Ʈ ���� �� �˾����� ���ڴµ� ��ĳ �˰� ���� ��������*/
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	if (KeyManager.IsKeyDown('W'))
	{
		fsm->SetCurState("Move");
	}
	if (KeyManager.IsKeyDown('A'))
	{
		fsm->SetCurState("Move");
	}
	if (KeyManager.IsKeyDown('S'))
	{
		fsm->SetCurState("Move");
	}
	if (KeyManager.IsKeyDown('D'))
	{
		fsm->SetCurState("Move");
	}
}

void IdleState::Exit()
{
	// ������ ������ ���� ������ �̾��� �� �ְ� ���� (�ִϸ��̼� ���ҽ��� �����ؼ� ����ī��Ʈ�� ��´�.(���ҽ� ���� ����)
	

}