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
	// 공격 상태에서 mid 바운드 박스를 넘어가면 공격 애니메이션을 끝까지 재생하고 이동을 시켜야함
	else if (DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmaxRect) &&
			!DemoApp::m_pPlayer->m_BoundBox.CheckIntersect(owner->BmidRect))
	{
		//fsm->SetCurState("EMove");
		
		// mid 바운드 박스가 아니면서 max 바운드 박스로 나갈 때
		// 판정이 Attack -> Move로 바뀌어야해
		// 이때 m_pAnimationProcesser 가 무언가를 가리켜야하는데...
	}
}

void EAttackState::Exit()
{
}

void EAttackState::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
	// 종료 조건이 되면 얘를 실행하게 될 거야
	// 그럼 이제 종료 조건을 어디다 만들어줄까
	// 일단 여기는 m_pAnimationProcesser가 있을 때 실행 돼
	// 그니까 m_pAnimationProcesser가 가리키는 대상이 누굴까
	
	// 여기서 애니매이션이 멈추고 이동하는 상태로 바꿔준다
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	fsm->SetCurState("EMove");
}
