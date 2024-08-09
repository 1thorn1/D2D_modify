#include "Background.h"

Background::Background()
{
	m_Background = GameObject::CreateComponent<BitmapScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/background.bmp", &(m_Background->m_pBitmap));
	m_Background->m_RelativeScale = { 1.65f,1.3f };
	//m_Background->GetOwner()->m_BoundBox.m_Extend = { size.width,size.height - 70 };
}

Background::~Background()
{
}

void Background::Initialize()
{
	D2D_SIZE_F size = m_Background->GetBitmap()->GetSize();
}

void Background::Update()
{
	__super::Update();
}

void Background::Render()
{
	__super::Render();
}
