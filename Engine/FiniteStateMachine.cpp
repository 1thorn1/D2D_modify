#include "pch.h"
#include "FiniteStateMachine.h"
#include "FSMState.h"

FiniteStateMachine::FiniteStateMachine()
{
}

FiniteStateMachine::~FiniteStateMachine()
{
	for (std::pair<std::string, FSMState*> state : m_pStates)
	{
		delete state.second;
	}
	m_pStates.clear();
}

void FiniteStateMachine::Update()
{
	if (m_pPreState != m_pCurrState) // ���� ���� -> ���� ���� �ٸ��ٸ�
	{
		if (m_pPreState != nullptr) // ���� ���°� ������ ��
		{
			m_pPreState->Exit(); // Exit ���� -> ���� ���¸� �������� 
		}
		m_pPreState = m_pCurrState; // -> ���� ���¿� ���� ���¸� �ֱ�
		m_pPreState->Enter(); // -> ���� ���¸� �����Ѵ�
	}
	else
	{
		m_pPreState->Update(); // ���� ���¿� ���� ���°� ���ٸ� -> loop ������
	}
}

void FiniteStateMachine::SetCurState(std::string stateName)
{
	auto it = m_pStates.find(stateName);
	if (it != m_pStates.end())
	{
		m_pCurrState = it->second;
	}
}
