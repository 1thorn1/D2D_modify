#pragma once
#include "../Engine/GameApp.h"

class Player;

class DemoApp : public GameApp
{
public:
	static Player* m_pPlayer;

	void Initialize(HINSTANCE hInstance);

	void LoadWorld();

	void CheckKeyInput();
	//void PrintUsedVRAM();
	void ScoreCount();

};

