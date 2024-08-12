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
	Debug.Log("아 외않되");
	InputManager KeyManager;

	if (KeyManager.IsKeyDown(VK_F1))
	{
		Debug.Log("in");
		SceneManager::SetActWorld("play");
	}

	// GameApp 루프에서 돌렸을 떄는 되는데 여기서는 안된다는 건 스크립트 루프를 안돈다는 뜻이겠지? 

}