#pragma once
#include "DemoApp.h"
#include "GameManager.h"


class TitleBackground : public GameObject
{
public:
	BitmapScene* m_titlebackground;
	CustomInput input;
	InputManager KeyManager;
	
	TitleBackground();
	virtual ~TitleBackground();

	virtual void Intialize();
	virtual void Update();
	virtual void Render();
};

