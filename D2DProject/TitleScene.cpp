#include "TitleScene.h"

TitleScene::~TitleScene()
{
	// ���ҽ� ����?
}

void TitleScene::Initialize()
{
	// ��, ������Ʈ ���
	Debug.Log("title ����");
	GameObject* obj = CreateGameObject<GameObject>();
	BitmapScene* bit = obj->CreateComponent<BitmapScene>();
	ResourceManager::CreateD2DBitmapFromFile(L"Asset/title.png", &bit->m_pBitmap);
	
	
	//if (KeyManager.IsKeyDown(VK_F1))
	//{
	//	Debug.Log("in");
	//	SceneManager::SetActWorld("play");
	//}
}

void TitleScene::WorldEnter()
{
	Debug.Log("enter"); 
}

void TitleScene::WorldExit()
{
}

