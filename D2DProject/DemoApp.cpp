#include "DemoApp.h"
#include "Object.h"
#include "SPlayer.h"
#include "Background.h"
#include "VBall.h"
#include "GameManager.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "TextScore.h"

void DemoApp::Initialize(HINSTANCE hInstance)
{
	TimeManager();

	__super::Initialize(hInstance);
	LoadWorld();
}

void DemoApp::LoadWorld()
{
	TitleScene *temp = SceneManager::CreateWorld<TitleScene>("title");
	SceneManager::CreateWorld<PlayScene>("play");
	SceneManager::SetActWorld(temp);
}

void DemoApp::Uninitialize()
{
	TextScore::Clear();
}
