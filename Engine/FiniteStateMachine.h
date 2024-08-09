#pragma once
#include "Component.h"

class FSMState;

class FiniteStateMachine
	: public Component
{
	FSMState* m_pCurrState = nullptr;			 // 현재 상태
	FSMState* m_pPreState = nullptr;			 // 이전 상태
	std::map<std::string, FSMState*> m_pStates;  // 생성된 FSMState 저장하기
public:
	FiniteStateMachine();
	~FiniteStateMachine();

	void Update();

	void SetCurState(std::string stateName);

	template<typename T>
	void CreateState(const std::string StateName) 
	{
		T* pState = new T(this, StateName); // T 클래스의 생성자에 전달
		pState->Initialize();
		// m_pStates 배열에 상태 pState를 pState->GetName()을 키값으로 삽입하기
		m_pStates.insert(std::make_pair(pState->GetName(), pState));
	}
};