#include "DemoApp.h"
#include "Object.h"
#include "SPlayer.h"
#include "Background.h"
#include "VBall.h"
#include "GameManager.h"
#include "TitleScene.h"
#include "PlayScene.h"

void DemoApp::Initialize(HINSTANCE hInstance)
{
	TimeManager();

	__super::Initialize(hInstance);
	LoadWorld();
	

	//SceneManager::CreateWorld<PlayScene>("play");

	//// 카메라 생성.
	//GameObject* clone;
	//clone = tempWorld.CreateGameObject<GameObject>();
	//clone->m_pRootScene = clone->CreateComponent<CameraScene>();
	//tempWorld.mainCamera = clone; // 메인카메라 설정 잊지말기!

	//clone = tempWorld.CreateGameObject<Background>();
	//GameManager::wall = tempWorld.CreateGameObject<Object>();

	//// 깃발
	//clone = tempWorld.CreateGameObject<GameObject>();
	//AnimationScene* flag = clone->CreateComponent<AnimationScene>();
	//ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/flag.png", &flag->m_pBitmap);
	//ResourceManager::pInstance->CreateAnimationAsset(L"CSV/flag.txt", &flag->m_pAnimationAsset);
	//flag->SetAnimation(4, 0);
	//flag->m_RelativeLocation = { 512 + 30 , 300 + 40 };
	//flag->m_RelativeScale = { 2.0f,2.0f };
	//clone->m_pRootScene = flag;


	//// 플레이어 1,2를 생성함
	//GameManager::p1 = tempWorld.CreateGameObject<SPlayer>();
	//GameManager::p2 = tempWorld.CreateGameObject<SPlayer>();
	//GameManager::p1->Initialize();

	//// Scene 생성
	////GameScenes->CreateWorld<TitleScene>("TitleScene");

	//GameManager::p1->input.up = 'W';
	//GameManager::p1->input.left = 'A';
	//GameManager::p1->input.down = 'S';
	//GameManager::p1->input.right = 'D';
	//GameManager::p1->input.enter = 'V';

	//clone = tempWorld.CreateGameObject<VBall>();
}

void DemoApp::LoadWorld()
{
	TitleScene *temp = SceneManager::CreateWorld<TitleScene>("title");
	SceneManager::CreateWorld<PlayScene>("play");
	SceneManager::SetActWorld(temp);
}

void DemoApp::CheckKeyInput()
{
	InputManager KeyManager;

	//if (KeyManager.IsKeyDown(VK_LEFT))
	//{
	//	tempWorld.mainCamera->m_pRootScene->m_RelativeLocation.x -= 1;
	//}
	//if (KeyManager.IsKeyDown(VK_RIGHT))
	//{
	//	tempWorld.mainCamera->m_pRootScene->m_RelativeLocation.x += 1;
	//}
}


void DemoApp::ScoreCount()
{
	D2D1_RECT_F rect = { 480,10, 700,100 };
	//std::wstring key = L" Score : " + std::to_wstring(VBall::count_p1);
	std::wstring key = std::to_wstring(VBall::count_p2) + L" : " + std::to_wstring(VBall::count_p1);

	/*D2DRender::GetRenderTarget()->DrawTextW(
		key.c_str(), static_cast<UINT32>(key.size()),
		D2DRender::GetIDWriteTextFormat(),
		rect,
		D2DRender::GetID2D1SolidColorBrush());*/

	ID2D1SolidColorBrush* outlineBrush = nullptr;
	ID2D1SolidColorBrush* textBrush = nullptr;

	D2DRender::GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black, 1.0f), &outlineBrush);
	D2DRender::GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::DarkOrange, 1.0f), &textBrush);

	D2DRender::GetRenderTarget()->DrawTextW
	(
		key.c_str(),
		static_cast<UINT32>(key.size()),

		D2DRender::GetIDWriteTextFormat(),
		rect,
		outlineBrush, // 외곽선 브러시
		D2D1_DRAW_TEXT_OPTIONS_NONE,
		DWRITE_MEASURING_MODE_NATURAL
	);

	D2DRender::GetRenderTarget()->DrawTextW
	(
		key.c_str(),
		static_cast<UINT32>(key.size()),
		D2DRender::GetIDWriteTextFormat(),
		rect,
		textBrush, // 텍스트 브러시
		D2D1_DRAW_TEXT_OPTIONS_NONE,
		DWRITE_MEASURING_MODE_NATURAL
	);

}
