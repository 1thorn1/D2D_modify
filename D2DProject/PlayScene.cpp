#include "PlayScene.h"
#include "PlayScript.h"


PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	// 씬, 오브젝트 등록
	Debug.Log("play 생성");
	GameObject* obj = CreateGameObject<GameObject>();
	BitmapScene* bit = obj->CreateComponent<BitmapScene>();
	Script* scr = obj->CreateComponent<Script>();
	scr->GetOwner()->GetComponent<Script>();

	GameObject* pobj = CreateGameObject<GameObject>();
	PlayScript* pscr = pobj->CreateComponent<PlayScript>();
	pscr->GetOwner()->GetComponent<PlayScript>();

	ResourceManager::CreateD2DBitmapFromFile(L"Asset/Background.bmp", &bit->m_pBitmap);
}

void PlayScene::WorldEnter()
{
	Debug.Log("enter"); // 여기가 호출되는 중 ㅇㅅㅇ
}

void PlayScene::WorldExit()
{
}


