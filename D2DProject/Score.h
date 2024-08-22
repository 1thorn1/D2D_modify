#pragma once
#include "DemoApp.h"

class Score : public GameObject
{
public:
	Score();
	~Score();

	void Initialize();
	void Update();
	void Render();
};

