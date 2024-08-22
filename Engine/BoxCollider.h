#pragma once
#include "Collider.h"

class BoxCollider : public Component
{
public:
	BoxCollider();
	virtual ~BoxCollider();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};

