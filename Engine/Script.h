#pragma once
#include "Component.h"

// Script Component는 특정 행동이나 동작을 제어하는 스크립트를 포함합니다.
// 예를 들어, 사용자가 버튼을 클릭했을 때 특정 동작을 실행하는 등의 기능을 구현할 수 있습니다.
// 머 대충 그렇습니다

class Script : public Component
{
public:
	Script() {};
	~Script() {};

	virtual void Initialize();
	virtual void Update();
	virtual void Render() {};
};

