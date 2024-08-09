#include "PlayScene.h"


PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	// 씬, 오브젝트 등록
	Debug.Log("play 생성");
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


