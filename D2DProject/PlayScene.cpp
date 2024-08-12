#include "PlayScene.h"


PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	// ��, ������Ʈ ���
	Debug.Log("play ����");
	GameObject* obj = CreateGameObject<GameObject>();
	BitmapScene* bit = obj->CreateComponent<BitmapScene>();
	Script* scr = obj->CreateComponent<Script>();
	scr->GetOwner()->GetComponent<Script>();

	ResourceManager::CreateD2DBitmapFromFile(L"Asset/Background.bmp", &bit->m_pBitmap);
}

void PlayScene::WorldEnter()
{
	Debug.Log("enter"); // ���Ⱑ ȣ��Ǵ� �� ������
}

void PlayScene::WorldExit()
{
}


