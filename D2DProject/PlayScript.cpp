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

	//Debug.Log("�÷��� ��ũ��Ʈ ������Ʈ");
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

