#pragma once
#include "Component.h"

// Script Component�� Ư�� �ൿ�̳� ������ �����ϴ� ��ũ��Ʈ�� �����մϴ�.
// ���� ���, ����ڰ� ��ư�� Ŭ������ �� Ư�� ������ �����ϴ� ���� ����� ������ �� �ֽ��ϴ�.
// �� ���� �׷����ϴ�

class Script : public Component
{
public:
	Script() {};
	~Script() {};

	virtual void Initialize();
	virtual void Update();
	virtual void Render() {};
};

