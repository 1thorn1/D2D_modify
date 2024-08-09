#pragma once
#include "World.h"

class World;

class SceneManager
{
	static World* m_ActiveWorld; // 현재 실행 중인 씬
	static World* m_LoadWorld;	
	
	static std::map<std::string, World*> m_pWorlds; // 씬들을 map 배열에 저장

	
public: 
	static void Update(); 
	static void Render(); 

	static World* FindWorld(std::string worldname)
	{
		for (auto it = m_pWorlds.begin(); it != m_pWorlds.end(); ++it)
		{
			std::string worldName = it->first;   // map의 key, world 이름
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
		pWorld->Initialize(); // world들을 초기화
		m_pWorlds.insert(std::make_pair(worldName, pWorld));

		return pWorld;
	}

};