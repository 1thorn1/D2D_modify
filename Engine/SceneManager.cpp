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
		if (m_ActiveWorld != m_LoadWorld && m_LoadWorld != nullptr) // ���� �� != ���� ��
		{
			if (m_ActiveWorld != nullptr) // ���� ���� ���� ��
			{
				m_ActiveWorld->WorldExit(); // Exit ���� -> ���� ���� �������� 
				m_ActiveWorld = m_LoadWorld; // -> ���� ���� ���� ���� �ֱ�
				m_ActiveWorld->WorldEnter(); // -> ���� ���� �����Ѵ�
			}
		}
	}
}

void SceneManager::SetActWorld(std::string WorldName)
{
	auto it = m_pWorlds.find(WorldName); // map���� ��� world ã��
	if (it != m_pWorlds.end()) // �̰� ������ ���� �ʰ� ������
	{
		m_LoadWorld = it->second; // map�� value��(world*)�� �־��ֱ�
	}
}

void SceneManager::SetActWorld(World* world)
{
	if (world) m_ActiveWorld = world;
}
    
