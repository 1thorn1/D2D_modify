#pragma once
#include "DemoApp.h"

// ������Ʈ, world ���� �����ַ��� �������
class PlayScript : public Script
{
public:
	PlayScript();
	~PlayScript();

	void Initialize();
	void Update();
	void Render();
};

