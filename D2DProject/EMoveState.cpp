#include "EMoveState.h"

void EMoveState::Enter()
{
	AnimationScene* EMoveAni;
	EMoveAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EMoveAni->LoadAnimationAsset(L"CSV/EMove.txt");
	EMoveAni->SetAnimation(6, 0);
}

void EMoveState::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();

	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmaxRect) &&
	   !DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		//fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 0.5;
		// �÷��̾��� ��ǥ�� ���ʹ� ��ǥ �Ÿ� ����ϱ�
		Vector2F direction = DemoApp::m_pPlayer->PlayerAni->m_RelativeLocation - owner->EnemyAni->m_RelativeLocation;
		direction.Normalize();
		direction *= owner->m_speed * 5;

		owner->EnemyAni->m_RelativeLocation += direction;
	}
	else
	{
		fsm->SetCurState("EIdle");
	}
	// �÷��̾ mid �ٿ�� �ڽ��� ������ Attack ��� ���ϱ�
	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->SetCurState("EAttack");
	}
}

void EMoveState::Exit()
{
}

void EMoveState::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
