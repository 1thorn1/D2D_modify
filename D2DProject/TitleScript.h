#pragma once
#include "DemoApp.h"

class TitleScript : public Script
{
public:
	TitleScript();
	~TitleScript();

	virtual void Initialize();
	virtual void Update();
	virtual void Render() {};

};

