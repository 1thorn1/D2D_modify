#include "TitleScript.h"

TitleScript::TitleScript()
{
}

TitleScript::~TitleScript()
{
}

void TitleScript::Initialize()
{
}

void TitleScript::Update()
{
	Debug.Log("�� �ܾʵ�");
	InputManager KeyManager;

	if (KeyManager.IsKeyDown(VK_F1))
	{
		Debug.Log("in");
		SceneManager::SetActWorld("play");
	}

	// GameApp �������� ������ ���� �Ǵµ� ���⼭�� �ȵȴٴ� �� ��ũ��Ʈ ������ �ȵ��ٴ� ���̰���? 

}