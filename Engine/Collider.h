#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider() {};
	virtual ~Collider() {};

	virtual void Initialize() {};
	virtual void Update() {};
	virtual void Render() {};
};

