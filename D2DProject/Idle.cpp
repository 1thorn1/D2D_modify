#include "Idle.h"
#include "GameManager.h"

void Idle::Enter()
{
	AnimationScene* IdleAni;
	IdleAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	IdleAni->LoadAnimationAsset(L"CSV/Idle.txt");
	IdleAni->SetAnimation(3, 0);

	GameManager::p1->SPlayerAni->m_bMirror = true;
}

void Idle::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// 플레이어의 콜라이더와 공의 콜라이더가 닿으면
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		// 점프 실행
		fsm->SetCurState("DJump");

	}
	if (KeyManager.IsKeyDown(owner->input.left))
	{
		// 그냥 현재 애니메이션 재생, 앞으로 이동
		fsm->SetCurState("SDRun");
	}

	if (KeyManager.IsKeyDown(owner->input.right))
	{
		// 그냥 현재 애니메이션 재생, 뒤으로 이동
		fsm->SetCurState("SDRun");
	}
}

void Idle::Exit()
{
}

void Idle::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
