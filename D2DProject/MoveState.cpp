#include "MoveState.h"

void MoveState::Enter()
{
	// Walk애니메이션 재생!
	//m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;

	AnimationScene* PMoveAni;
	PMoveAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	PMoveAni->LoadAnimationAsset(L"CSV/KenMove.txt");
	PMoveAni->SetAnimation(3, 0);
	m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
}

void MoveState::Update()
{
	/*특정 키 눌렀을 때 특정 Walk 스프라이트가 작동하게끔
	플레이어 애니메이션의 루트 씬인 걸 알았으면 좋겠는데 어캐 알게 하지 ㅇㅅㅇㅠ*/
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	if (KeyManager.IsKeyDown('W'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.y -= 1;
	}
	if (KeyManager.IsKeyDown('S'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.y += 1;
	}
	if (KeyManager.IsKeyDown('A'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
	}
	if (KeyManager.IsKeyDown('D'))
	{
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;
	}

	if (!KeyManager.IsKeyDown('W') &&
		!KeyManager.IsKeyDown('S') &&
		!KeyManager.IsKeyDown('A') &&
		!KeyManager.IsKeyDown('D'))
	{
		fsm->SetCurState("Idle");
	} 
}
void MoveState::Exit()
{
}
