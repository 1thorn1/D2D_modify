#include "Attack.h"

void Attack::Enter()
{
	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/Attack.txt");
	DRunAni->SetAnimation(0, 0);
	GameManager::p1->SPlayerAni->m_bMirror = true;
}

void Attack::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	float speed = 200.0f;
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			 // 중력을 계속 받아서 점프를 해야함 -> 수정 필요
			owner->Setvelocity(owner->Getvelocity() + owner->GetGravityScale() * TimeManager::GetDeltaTime());
			
		}
		if (KeyManager.IsKeyDown(owner->input.right))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 0.1 * speed * TimeManager::GetDeltaTime();
		}
		if (KeyManager.IsKeyDown(owner->input.left))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 0.1 * speed * TimeManager::GetDeltaTime();
		}
	}

	owner->Setvelocity(owner->Getvelocity() + owner->GetGravityScale() * TimeManager::GetDeltaTime());
	owner->m_pRootScene->m_RelativeLocation.y += owner->Getvelocity() * TimeManager::GetDeltaTime();

	if (owner->m_pRootScene->m_RelativeLocation.y >= 500)
	{
		owner->m_pRootScene->m_RelativeLocation.y = 500;
		fsm->SetCurState("PIdle");
	}
	else
	{
		if (KeyManager.IsKeyDown(owner->input.right))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x += 1;
		}
		if (KeyManager.IsKeyDown(owner->input.left))
		{
			fsm->GetOwner()->m_pRootScene->m_RelativeLocation.x -= 1;
		}
	}
}

void Attack::Exit()
{
}

void Attack::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
