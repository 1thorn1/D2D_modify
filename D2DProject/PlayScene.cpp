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

	ResourceManager::CreateD2DBitmapFromFile(L"Asset/Background.bmp", &bit->m_pBitmap);
}

void PlayScene::WorldEnter()
{
	Debug.Log("enter");
}

void PlayScene::WorldExit()
{
}


