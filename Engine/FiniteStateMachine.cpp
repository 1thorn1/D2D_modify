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
	if (m_pPreState != m_pCurrState) // 이전 상태 -> 현재 상태 다르다면
	{
		if (m_pPreState != nullptr) // 이전 상태가 존재할 때
		{
			m_pPreState->Exit(); // Exit 실행 -> 이전 상태를 빠져나옴 
		}
		m_pPreState = m_pCurrState; // -> 이전 상태에 현재 상태를 넣기
		m_pPreState->Enter(); // -> 현재 상태를 실행한다
	}
	else
	{
		m_pPreState->Update(); // 이전 상태와 현재 상태가 같다면 -> loop 돌리기
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
