#pragma once
#include "GameObject.h"

class GameObject;

class World
{
public:
	World(const std::string& worldname) : m_WorldName(worldname) {}
	virtual ~World();
	
	std::list<GameObject*> m_GameObjects; // ���� ������Ʈ ���
	
	int count = 0; // �ø����� �ʰ� ī�޶� ��µǴ� ������Ʈ ��
	GameObject* mainCamera; // ���� ������Ʈ �� ���� ī�޶�
	std::string m_WorldName; // ��� ���� ������ �̸�

public:
	void Initialize();
	void Update();
	void Render();
	void Clear();

	virtual void WorldEnter() {};
	virtual void WorldExit() {};
	//virtual void WorldLoad() = 0;

	template<typename T>
	T* CreateGameObject()
	{
		bool bIsBase = std::is_base_of<GameObject, T>::value; // T�� GameObject�� ��ӹ���
		assert(bIsBase == true);
		T* newObject = new T();
		newObject->SetOwner(this); // ������ ��ü�� ������ ����, this�� CreateGameObject �Լ��� ���� Ŭ������ �ν��Ͻ��� ����Ŵ -> ���� �������
		m_GameObjects.push_back(newObject);
		return newObject;
	}
};

