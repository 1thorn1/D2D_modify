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
	 /*특정 키 눌렀을 때 특정 Walk 스프라이트가 작동하게끔
	 플레이어 애니메이션의 루트 씬인 걸 알았으면 좋겠는데 어캐 알게 하지 ㅇㅅㅇㅠ*/
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
	// 동작을 끝내고 다음 동작이 이어질 수 있게 만듦 (애니메이션 리소스를 삭제해서 참조카운트를 깎는다.(리소스 관리 전략)
	

}