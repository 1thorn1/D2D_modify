#pragma once
#include "DemoApp.h"


class PlayScene : public World

{
public:

	InputManager KeyManager;

	PlayScene(const std::string& name) : World(name){}
	virtual ~PlayScene();
	
	void Initialize();
	void WorldEnter();
	void WorldExit();
};

