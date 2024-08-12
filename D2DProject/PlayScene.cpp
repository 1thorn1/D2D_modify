#include "PlayScene.h"
#include "PlayScript.h"


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

	GameObject* pobj = CreateGameObject<GameObject>();
	PlayScript* pscr = pobj->CreateComponent<PlayScript>();
	pscr->GetOwner()->GetComponent<PlayScript>();

	ResourceManager::CreateD2DBitmapFromFile(L"Asset/Background.bmp", &bit->m_pBitmap);
}

void PlayScene::WorldEnter()
{
	Debug.Log("enter"); // ���Ⱑ ȣ��Ǵ� �� ������
}

void PlayScene::WorldExit()
{
}


