#pragma once
#include "DemoApp.h"

class PlayScript : public Script
{
public:
	PlayScript();
	~PlayScript();

	void Initialize();
	void Update();
	void Render();
};

