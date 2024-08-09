#pragma once
#include "DemoApp.h"
#include "GameManager.h"

class Object : public GameObject
{
public:

	BitmapScene* m_Object;
	static Vector2F ob_velocity;

	Object();
	virtual ~Object();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};

