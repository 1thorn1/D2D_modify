#include "TitleScene.h"
#include "TitleScript.h"

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
	Script* scr = obj->CreateComponent<Script>();
	scr->GetOwner()->GetComponent<Script>();
	bit->m_RelativeLocation = { 130,-50 };
	bit->m_RelativeScale = { 1.2f,1.2f };

	GameObject* pobj = CreateGameObject<GameObject>();
	TitleScript* tscr = pobj->CreateComponent<TitleScript>();
	tscr->GetOwner()->GetComponent<TitleScript>();

	ResourceManager::CreateD2DBitmapFromFile(L"Asset/title.png", &bit->m_pBitmap);
}

void TitleScene::WorldEnter()
{
	Debug.Log("titlescene enter");  
	// ���� �ȵǴ� �� GameApp���� Update ȣ���� ����� ����
	// World -> Object -> Component ���� update loop�� ���������
}

void TitleScene::WorldExit()
{
}

