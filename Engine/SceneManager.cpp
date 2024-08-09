#include "pch.h"
#include "SceneManager.h"

World* SceneManager::m_ActiveWorld = nullptr;
World* SceneManager::m_LoadWorld = nullptr;

std::map<std::string, World*> SceneManager::m_pWorlds;

void SceneManager::Update()
{
	if (m_ActiveWorld)
		m_ActiveWorld->Update();
}

void SceneManager::Render()
{
	if (m_ActiveWorld)
		m_ActiveWorld->Render();
}

void SceneManager::ChangeWorld()
{
	if (m_ActiveWorld)
	{
		if (m_ActiveWorld != m_LoadWorld && m_LoadWorld != nullptr) // 현재 씬 != 다음 씬
		{
			if (m_ActiveWorld != nullptr) // 현재 씬이 있을 때
			{
				m_ActiveWorld->WorldExit(); // Exit 실행 -> 현재 씬을 빠져나옴 
				m_ActiveWorld = m_LoadWorld; // -> 현재 씬에 다음 씬을 넣기
				m_ActiveWorld->WorldEnter(); // -> 현재 씬을 실행한다
			}
		}
	}
}

void SceneManager::SetActWorld(std::string WorldName)
{
	auto it = m_pWorlds.find(WorldName); // map에서 모든 world 찾기
	if (it != m_pWorlds.end()) // 이게 끝까지 가지 않고 있으면
	{
		m_LoadWorld = it->second; // map의 value값(world*)를 넣어주기
	}
}

void SceneManager::SetActWorld(World* world)
{
	if (world) m_ActiveWorld = world;
}
    
