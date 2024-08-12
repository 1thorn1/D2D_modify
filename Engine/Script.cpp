#include "pch.h"
#include "Script.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Debug.h"

void Script::Initialize()
{
	// 무언가 초기화 할 것들?
}
void Script::Update()
{
	__super::Update();
	Debug.Log("스크립트");
}
