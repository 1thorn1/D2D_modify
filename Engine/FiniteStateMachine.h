#pragma once
#include "Component.h"

class FSMState;

class FiniteStateMachine
	: public Component
{
	FSMState* m_pCurrState = nullptr;			 // ���� ����
	FSMState* m_pPreState = nullptr;			 // ���� ����
	std::map<std::string, FSMState*> m_pStates;  // ������ FSMState �����ϱ�
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void Update();

	void SetCurState(std::string stateName);

	template<typename T>
	void CreateState(const std::string StateName) 
	{
		T* pState = new T(this, StateName); // T Ŭ������ �����ڿ� ����
		pState->Initialize();
		// m_pStates �迭�� ���� pState�� pState->GetName()�� Ű������ �����ϱ�
		m_pStates.insert(std::make_pair(pState->GetName(), pState));
	}
};