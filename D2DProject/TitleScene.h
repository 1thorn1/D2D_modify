#pragma once
#include "DemoApp.h"

class TitleScene : public World
{

public:
	InputManager KeyManager;

	TitleScene(const std::string& name) : World(name) {}
	virtual ~TitleScene();

	void Initialize();
	void WorldEnter();
	void WorldExit();
};

