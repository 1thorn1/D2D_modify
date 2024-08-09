#include "SDRun.h"
#include "GameManager.h"

void SDRun::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/DRun.txt");
	DRunAni->SetAnimation(1, 0);
}

void SDRun::Update()
{
	float speed = 300.0f;
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// 플레이어의 콜라이더와 공의 콜라이더가 닿으면
	// 중력과 탄성을 받아 공을 튀기기
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		// 점프 실행
		fsm->SetCurState("DJump");
	}

	if (KeyManager.IsKeyDown(owner->input.left))
	{
		// 그냥 현재 애니메이션 재생, 앞으로 이동
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1 * speed * TimeManager::GetDeltaTime();
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = false;

		// 세이브 모션 취하기
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
		}
	}

	if (KeyManager.IsKeyDown(owner->input.right))
	{
		// 그냥 현재 애니메이션 재생, 뒤으로 이동
		fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1 * speed * TimeManager::GetDeltaTime();
		m_pOwner->GetOwner()->GetComponent<AnimationScene>()->m_bMirror = true;
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			// 세이브 모션 취하기
		}
	}

	if (!KeyManager.IsKeyDown(owner->input.left) && !KeyManager.IsKeyDown(owner->input.right))
	{
		fsm->SetCurState("PIdle");
	}
}

void SDRun::Exit()
{
}

void SDRun::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
