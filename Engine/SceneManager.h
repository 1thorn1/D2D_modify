#pragma once
#include "World.h"

class World;

class SceneManager
{
	static World* m_ActiveWorld; // ���� ���� ���� ��
	static World* m_LoadWorld;	
	
	static std::map<std::string, World*> m_pWorlds; // ������ map �迭�� ����

	
public: 
	static void Update(); 
	static void Render(); 

	static World* FindWorld(std::string worldname)
	{
		for (auto it = m_pWorlds.begin(); it != m_pWorlds.end(); ++it)
		{
			std::string worldName = it->first;   // map�� key, world �̸�
			World* world = it->second;
		}
	}
	static void ChangeWorld();

	static void SetActWorld(std::string WorldName);
	static void SetActWorld(World* world);

	template <typename T>
	static T* CreateWorld(const std::string worldName)
	{
		T* pWorld = new T(worldName);
		pWorld->Initialize(); // world���� �ʱ�ȭ
		m_pWorlds.insert(std::make_pair(worldName, pWorld));

		return pWorld;
	}

};