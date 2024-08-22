#include "VBall.h"
#include "Object.h"
#include "SPlayer.h"
#include "GameManager.h"

AnimationScene* VBall::m_Ball = nullptr;
int VBall::count_p1 = 0;
int VBall::count_p2 = 0;


VBall::VBall()
{
	m_Ball = CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/Vball.png", &m_Ball->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(L"CSV/DBall.txt", &m_Ball->m_pAnimationAsset);
	SetRootScene(m_Ball);
	m_Ball->SetAnimation(5, 0);
	m_Ball->m_RelativeLocation = { 512 + 200, 350 };
	m_Ball->m_RelativeScale = { 1.8f,1.8f };

	position = 0.0f;
	isBound = false;
	Initialize();
}

VBall::~VBall()
{
}

bool VBall::CheckCollision(Vector2F& location, float radius)
{
	Vector2F diff = m_Ball->m_RelativeLocation - location;
	float distance = diff.length();
	return distance < (m_Ball->m_DstRect.bottom * 0.5 + radius);
}

void VBall::ResolveCollision(Vector2F& location, Vector2F& velocity, float radius)
{
	// ���⺤�� ����ȭ
	Vector2F CollisionNormal = (m_Ball->m_RelativeLocation - location).normalize();
	// �����ϱ�?
	Vector2F RelativeVelocity = vb_velocity - velocity;

	float VelocityAlongNormal = RelativeVelocity.dot(CollisionNormal);

	if (VelocityAlongNormal > 0)
	{
		return;
	}

	// �ݻ�����׿�?
	float e = 0.3f;

	float j = -(1 + e) * VelocityAlongNormal; // �ݻ��� ����
	// �ݻ��� ����
	//j /= (1 / (m_Ball->m_DstRect.bottom * 0.5) + 1 / (SPlayer::SPlayerAni->m_DstRect.bottom * 0.5));

	Vector2F impulse = CollisionNormal * j;
	vb_velocity += impulse * (1 / (m_Ball->m_DstRect.bottom * 0.5));
	velocity += impulse * (1 / (radius * 0.5));
}

void VBall::Initialize()
{
	this->gravityScale = 300.f;
}

void VBall::Update()
{
	//Debug.Log("ball update");
	__super::Update();

	float time = TimeManager::GetDeltaTime();

	vb_velocity.y += gravityScale * time;
	m_Ball->GetOwner()->m_pRootScene->m_RelativeLocation += vb_velocity * time;

	GameManager::wall->m_Object->m_RelativeLocation.x;
	GameManager::p2->SPlayerAni->m_RelativeLocation;
	// ��Ʈ�� ���� x��ǥ�� ��Ʈ�� ���� y������� �浹ó�� ����
	if (m_Ball->m_RelativeLocation.y + m_Ball->m_DstRect.bottom * 0.5 >= 272)
	{
		// ��Ʈ�� ������ x��ǥ�� ��Ʈ�� ���� y������� �浹ó�� ����
		if (m_Ball->m_RelativeLocation.x - m_Ball->m_DstRect.bottom * 0.5
			<= GameManager::wall->m_Object->m_RelativeLocation.x + 9
			&& m_Ball->m_RelativeLocation.x
			>= GameManager::wall->m_Object->m_RelativeLocation.x + 9)
		{
			Debug.Log("������");
			m_Ball->m_RelativeLocation.x
				= GameManager::wall->m_Object->m_RelativeLocation.x + 9 + m_Ball->m_DstRect.bottom;
			vb_velocity.x *= -0.8f;
		}

		// ��Ʈ�� ���� x��ǥ�� ��Ʈ�� ���� y������� �浹ó�� ����
		if (m_Ball->m_RelativeLocation.x + m_Ball->m_DstRect.bottom * 0.5
			>= GameManager::wall->m_Object->m_RelativeLocation.x - 9
			&& m_Ball->m_RelativeLocation.x
			<= GameManager::wall->m_Object->m_RelativeLocation.x - 9)
		{
			Debug.Log("��");
			m_Ball->m_RelativeLocation.x
				= GameManager::wall->m_Object->m_RelativeLocation.x - 9 - m_Ball->m_DstRect.bottom;
			vb_velocity.x *= -0.8f;
		}
	}

	// ������ ���� �������� ��������
	if (m_Ball->m_RelativeLocation.x + m_Ball->m_DstRect.bottom * 0.5 > SCREEN_WIDTH)
	{
		m_Ball->m_RelativeLocation.x = SCREEN_WIDTH - m_Ball->m_DstRect.bottom * 0.5;
		vb_velocity.x *= -0.5f;
	}

	// ���� ���� �������� ��������
	if (m_Ball->m_RelativeLocation.x - m_Ball->m_DstRect.bottom * 0.5 < 0)
	{
		m_Ball->m_RelativeLocation.x = 0 + m_Ball->m_DstRect.bottom * 0.5;
		vb_velocity.x *= -0.5f;
	}
	// ���� ���� �� ó��
	if (m_Ball->m_RelativeLocation.y >= 500 - m_Ball->m_DstRect.bottom * 0.5)
	{
		m_Ball->m_RelativeLocation.y = 500 - m_Ball->m_DstRect.bottom * 0.5;
		vb_velocity.y *= -0.5f;

		// 2�� ������
		static float delay = 0;
		//delay += TimeManager::GetDeltaTime();

		// �����������ž���
		int �� = 1;
		{
		//player 1 ��
			if (m_Ball->m_RelativeLocation.x - m_Ball->m_DstRect.bottom * 0.5
				<= GameManager::wall->m_Object->m_RelativeLocation.x + 9)
			{
				count_p1++;
				m_Ball->m_RelativeLocation = { 512 - 200, 350 };
				vb_velocity = { 0, 0 };
				GameManager::p1->SPlayerAni->m_RelativeLocation = { 512 - 200 , 600 - 100 };
				GameManager::p2->SPlayerAni->m_RelativeLocation = { 512 + 200 , 600 - 100 };
				// ���⿡ 1.0�ʰ� ������ �ɷȴٰ� �ٽ� �����ϰ� �ϰ����
			}
			//player 2 ��
			if (m_Ball->m_RelativeLocation.x + m_Ball->m_DstRect.bottom * 0.5
				>= GameManager::wall->m_Object->m_RelativeLocation.x - 9)
			{
				count_p2++;
				m_Ball->m_RelativeLocation = { 512 + 200, 350 };
				vb_velocity = { 0, 0 };
				GameManager::p1->SPlayerAni->m_RelativeLocation = { 512 - 200 , 600 - 100 };
				GameManager::p2->SPlayerAni->m_RelativeLocation = { 512 + 200 , 600 - 100 };
			}
		}
	}
	// ���� ���� �������� ��������
	if (m_Ball->m_RelativeLocation.y <= 0 + m_Ball->m_DstRect.bottom * 0.5)
	{
		m_Ball->m_RelativeLocation.y = 10 + m_Ball->m_DstRect.bottom * 0.5;
		vb_velocity.y *= -0.5f;
	}

	if (CheckCollision(GameManager::p1->SPlayerAni->m_RelativeLocation, GameManager::p1->SPlayerAni->m_DstRect.bottom * 0.5))
	{
		ResolveCollision(GameManager::p1->SPlayerAni->m_RelativeLocation, SPlayer::sp_velocity, GameManager::p1->SPlayerAni->m_DstRect.bottom * 0.5);
	}
	if (CheckCollision(GameManager::p2->SPlayerAni->m_RelativeLocation, GameManager::p2->SPlayerAni->m_DstRect.bottom * 0.5))
	{
		ResolveCollision(GameManager::p2->SPlayerAni->m_RelativeLocation, SPlayer::sp_velocity, GameManager::p2->SPlayerAni->m_DstRect.bottom * 0.5);
	}
}

void VBall::Render()
{
	__super::Render();
}
