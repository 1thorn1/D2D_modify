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
	// 플레이어가 mid 바운드 박스로 들어오면 Attack 모션 취하기
	if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		fsm->SetCurState("EAttack");
	}


	// player주소를 미리 알고있어야댐. <- 플레이어 하나만 충돌검사할 때 좋음.
}

void EIdleState::Exit()
{
}

void EIdleState::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
