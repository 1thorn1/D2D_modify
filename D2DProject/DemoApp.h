#pragma once
#include "../Engine/GameApp.h"


class DemoApp : public GameApp
{
public:

	void Initialize(HINSTANCE hInstance);
	void LoadWorld();
	void Uninitialize();

};

