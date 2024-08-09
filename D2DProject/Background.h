#pragma once
#include "DemoApp.h"

class Background : public GameObject
{
public:
	BitmapScene* m_Background;

	Background();
	virtual ~Background();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};
