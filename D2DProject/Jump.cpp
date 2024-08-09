#include "Jump.h"
#include "GameManager.h"

void Jump::Initialize()
{
	owner->SetGravityScale(600.f);
	owner->SetJumpForce(300.f);
	owner->SetPosition(0.0f);
	bool isJumping = false;
}

void Jump::Enter()
{
	owner->Setvelocity(-1.5 * owner->GetJumpForce());
	isJumping = false;

	AnimationScene* DRunAni;
	DRunAni = m_pOwner->GetOwner()->GetComponent<AnimationScene>();
	DRunAni->LoadAnimationAsset(L"CSV/Jump.txt");
	DRunAni->SetAnimation(2, 0);
	GameManager::p1->SPlayerAni->m_bMirror = true;
}

void Jump::Update()
{
	FiniteStateMachine* fsm = m_pOwner->GetOwner()->GetComponent<FiniteStateMachine>();
	// jump �ִϸ��̼� ���� ��� -> ���� ������ �� ����
	// ���� �ִϸ��̼��� ������ idle or jump ���·� ����
	// ���� �ݶ��̴��� �÷��̾��� �ݶ��̴��� ������ Attack ������� ����
	float speed = 200.0f;
	if (KeyManager.IsKeyDown(owner->input.up))
	{
		if (KeyManager.IsKeyDown(VK_RETURN))
		{
			fsm->SetCurState("PAttack");
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
		Debug.Log("��������");
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

void Jump::Exit()
{
}

void Jump::OnAnimationEnd(AnimationScene* pComponent, const std::string& AnimationName)
{
}
