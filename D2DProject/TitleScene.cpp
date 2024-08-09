#include "TitleScene.h"

TitleScene::~TitleScene()
{
	// 리소스 해제?
}

void TitleScene::Initialize()
{
	// 씬, 오브젝트 등록
	Debug.Log("title 생성");
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

