#include "PlayScene.h"
#include "PlayScript.h"
#include "GameManager.h"
#include "VBall.h"
#include "SPlayer.h"
#include "Object.h"

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
	bit->m_RelativeScale = { 1.65f,1.3f };

	GameObject* pobj = CreateGameObject<GameObject>();
	PlayScript* pscr = pobj->CreateComponent<PlayScript>();
	pscr->GetOwner()->GetComponent<PlayScript>();

	ResourceManager::CreateD2DBitmapFromFile(L"Asset/Background.bmp", &bit->m_pBitmap);

	// wall�� ������ 
	GameManager::wall = this->CreateGameObject<Object>();
	
	// ���
	GameObject* clone = this->CreateGameObject<GameObject>();
	AnimationScene* flag = clone->CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/flag.png", &flag->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(L"CSV/flag.txt", &flag->m_pAnimationAsset);
	flag->SetAnimation(4, 0);
	flag->m_RelativeLocation = { 512 + 40 , 300 + 40 };
	flag->m_RelativeScale = { 2.0f,2.0f };
	clone->m_pRootScene = flag;


	// �÷��̾� 1,2�� ������
	GameManager::p1 = this->CreateGameObject<SPlayer>();
	GameManager::p2 = this->CreateGameObject<SPlayer>();
	GameManager::p1->Initialize();

	GameManager::p1->input.up = 'W';
	GameManager::p1->input.left = 'A';
	GameManager::p1->input.down = 'S';
	GameManager::p1->input.right = 'D';
	GameManager::p1->input.enter = 'V';

	clone = this->CreateGameObject<VBall>();
}

void PlayScene::WorldEnter()
{
	Debug.Log("enter"); // ���Ⱑ ȣ��Ǵ� �� ������
}

void PlayScene::WorldExit()
{
}


