#include "EAttackState.h"

void EAttackState::Enter()
{
	AnimationScene* EMoveAni;
	EMoveAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	EMoveAni->LoadAnimationAsset(L"CSV/EAttack.txt");
	EMoveAni->SetAnimation(5, 0);

	EMoveAni->m_pAnimationProcesser = this;
}

void EAttackState::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 0;
	}
	// ���� ���¿��� mid �ٿ�� �ڽ��� �Ѿ�� ���� �ִϸ��̼��� ������ ����ϰ� �̵��� ���Ѿ���
	else if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmaxRect) &&
			!DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		//fsm->SetCurState("EMove");
		
		// mid �ٿ�� �ڽ��� �ƴϸ鼭 max �ٿ�� �ڽ��� ���� ��
		// ������ Attack -> Move�� �ٲ�����
		// �̶� m_pAnimationProcesser �� ���𰡸� �����Ѿ��ϴµ�...
	}
}

void EAttackState::Exit()
{
}

void EAttackState::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
	// ���� ������ �Ǹ� �긦 �����ϰ� �� �ž�
	// �׷� ���� ���� ������ ���� ������ٱ�
	// �ϴ� ����� m_pAnimationProcesser�� ���� �� ���� ��
	// �״ϱ� m_pAnimationProcesser�� ����Ű�� ����� ������
	
	// ���⼭ �ִϸ��̼��� ���߰� �̵��ϴ� ���·� �ٲ��ش�
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	fsm->SetCurState("EMove");
}
