#include "PlayScript.h"

PlayScript::PlayScript()
{
}

PlayScript::~PlayScript()
{
}

void PlayScript::Initialize()
{
}

void PlayScript::Update()
{
	__super::Update();

	//Debug.Log("플레이 스크립트 업데이트");
	InputManager KeyManager;

	if (KeyManager.IsKeyDown(VK_F2))
	{
		SceneManager::SetActWorld("title");
	}

}

void PlayScript::Render()
{
	__super::Render();
}

