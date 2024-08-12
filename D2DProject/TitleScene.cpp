#include "TitleScene.h"
#include "TitleScript.h"

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
	Script* scr = obj->CreateComponent<Script>();
	scr->GetOwner()->GetComponent<Script>();

	GameObject* pobj = CreateGameObject<GameObject>();
	TitleScript* tscr = pobj->CreateComponent<TitleScript>();
	tscr->GetOwner()->GetComponent<TitleScript>();

	ResourceManager::CreateD2DBitmapFromFile(L"Asset/title.png", &bit->m_pBitmap);
}

void TitleScene::WorldEnter()
{
	Debug.Log("enter");  
	// 엔터 안되는 중 GameApp에서 Update 호출을 멈췄기 때문
	// World -> Object -> Component 에서 update loop를 돌려줘야함
}

void TitleScene::WorldExit()
{
}

