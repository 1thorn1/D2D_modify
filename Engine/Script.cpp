#include "pch.h"
#include "Script.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Debug.h"

void Script::Initialize()
{
	// ���� �ʱ�ȭ �� �͵�?
}
void Script::Update()
{
	__super::Update();
	Debug.Log("��ũ��Ʈ");
}
