#include "Object.h"
#include "SPlayer.h"

Vector2F     Object::ob_velocity = { 0.0f,0.0f };

Object::Object()
{
	m_Object = GameObject::CreateComponent<BitmapScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/Cflag.png", &m_Object->m_pBitmap);
	m_Object->m_RelativeLocation = { 512,300 };
	D2D_SIZE_F size = m_Object->GetBitmap()->GetSize();
	m_Object->GetOwner()->m_BoundBox.m_Extend = { size.width,size.height };
	SetRootScene(m_Object);
}

Object::~Object()
{
}

void Object::Initialize()
{
}

void Object::Update()
{
	__super::Update();
	// 막대 오브젝트의 x 좌표 >= 플레이어 애니메이션 x좌표 - 플레이어 애니메이션 너비이면,
	// 플레이어 모션이 x 좌표보다 작아지지 못하게 하기
	if (m_Object->m_RelativeLocation.x + 9 + GameManager::p2->SPlayerAni->m_DstRect.bottom * 0.5
		> GameManager::p2->SPlayerAni->m_RelativeLocation.x)
	{
		Debug.Log("m_Object->m_RelativeLocation.x: "
			+ std::to_string(GameManager::p2->SPlayerAni->m_RelativeLocation.x));
		GameManager::p2->SPlayerAni->m_RelativeLocation.x
			= m_Object->m_RelativeLocation.x + 9 + GameManager::p2->SPlayerAni->m_DstRect.bottom * 0.5;
	}
	else if (m_Object->m_RelativeLocation.x - 9 - GameManager::p1->SPlayerAni->m_DstRect.bottom * 0.5
		< GameManager::p1->SPlayerAni->m_RelativeLocation.x)
	{
		Debug.Log("m_Object->m_RelativeLocation.x: "
			+ std::to_string(GameManager::p1->SPlayerAni->m_RelativeLocation.x));
		GameManager::p1->SPlayerAni->m_RelativeLocation.x
			= m_Object->m_RelativeLocation.x -9 - GameManager::p1->SPlayerAni->m_DstRect.bottom * 0.5;
	}



}

void Object::Render()
{
	__super::Render();
}
