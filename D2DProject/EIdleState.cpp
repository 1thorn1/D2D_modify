#include "EIdleState.h"

void EIdleState::Enter()
{
	AnimationScene* EIdleAni;
	EIdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EIdleAni->LoadAnimationAsset(L"CSV/EIdle.txt");
	EIdleAni->SetAnimation(4, 0);
}

void EIdleState::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();

	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmaxRect))
	{
		fsm->SetCurState("EMove");
	}
	// �÷��̾ mid �ٿ�� �ڽ��� ������ Attack ��� ���ϱ�
	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->SetCurState("EAttack");
	}


	// player�ּҸ� �̸� �˰��־�ߴ�. <- �÷��̾� �ϳ��� �浹�˻��� �� ����.
}

void EIdleState::Exit()
{
}

void EIdleState::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
