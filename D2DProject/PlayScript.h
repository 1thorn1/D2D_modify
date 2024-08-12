#pragma once
#include "DemoApp.h"

// 컴포넌트, world 루프 돌려주려고 만들었음
class PlayScript : public Script
{
public:
	PlayScript();
	~PlayScript();

	void Initialize();
	void Update();
	void Render();
};

