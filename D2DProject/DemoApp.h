#pragma once
#include "../Engine/GameApp.h"


class DemoApp : public GameApp
{
public:

	void Initialize(HINSTANCE hInstance);

	void LoadWorld();

	void CheckKeyInput();
	//void PrintUsedVRAM();
	void ScoreCount();

	void Uninitialize();

};

