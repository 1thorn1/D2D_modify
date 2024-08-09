#include "SPlayer.h"
#include "GameManager.h"
#include "Object.h"
#include "SDRun.h"
#include "Idle.h"
#include "Attack.h"
#include "Jump.h"
Vector2F SPlayer::sp_velocity(0.0f, 0.0f); // ���� �̸� �� �� �����ϰ� ���� �򰥸�

SPlayer::SPlayer()
{
	SPlayerAni = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/realpikachuuu.png", &SPlayerAni->m_pBitmap);
	SetRootScene(SPlayerAni);
	SPlayerAni->m_RelativeScale = { 2.f,2.f };

	fsm = CreateComponent<FiniteStateMachine>();
	fsm->CreateState<Attack>("PAttack");
	fsm->CreateState<Idle>("PIdle");
	fsm->CreateState<SDRun>("SDRun");
	fsm->CreateState<Jump>("DJump");
	fsm->SetCurState("PIdle");
}

SPlayer::~SPlayer()
{
}

void SPlayer::Initialize()
{
	GameManager::p1->SPlayerAni->m_RelativeLocation = { 512 - 200 , 600 - 100 };
	GameManager::p2->SPlayerAni->m_RelativeLocation = { 512 + 200 , 600 - 100 };
}

void SPlayer::Update()
{
	__super::Update();
	// �÷��̾��� x ��ǥ�� 1024�� ��
	// �÷��̾� ����� x ��ǥ���� Ŀ���� �ʰ��ϱ�  
	if (SPlayerAni->m_RelativeLocation.x >= GameManager::wall->m_Object->m_RelativeLocation.x + 9)
	{
		if (SPlayerAni->m_RelativeLocation.x + SPlayerAni->m_DstRect.bottom * 0.5 > SCREEN_WIDTH)
		{
			SPlayerAni->m_RelativeLocation.x = SCREEN_WIDTH - SPlayerAni->m_DstRect.bottom * 0.5;
		}
	}
	else if (SPlayerAni->m_RelativeLocation.x <= GameManager::wall->m_Object->m_RelativeLocation.x - 9)
	{
		if (SPlayerAni->m_RelativeLocation.x - SPlayerAni->m_DstRect.bottom * 0.5 < 0)
		{
			SPlayerAni->m_RelativeLocation.x = 0 + SPlayerAni->m_DstRect.bottom * 0.5;
		}
	}
}

void SPlayer::Render()
{
	__super::Render();
}
