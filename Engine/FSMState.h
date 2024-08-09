#pragma once

class FiniteStateMachine;

class FSMState //interface
{
public:
	FSMState(FiniteStateMachine* pOwner, std::string Name)
		:m_pOwner(pOwner)
		, m_Name(Name)
	{}
	~FSMState() {}

	std::string m_Name;
	FiniteStateMachine* m_pOwner;

public:
	void SetOwner(FiniteStateMachine* pOwner) { m_pOwner = pOwner; }
	const std::string& GetName() { return m_Name; }

	virtual void Initialize() {}
	virtual void Enter()  = 0;	// 이 기능이 있고 구현은 너가 하삼 
	virtual void Update() = 0;
	virtual void Exit()   = 0;
};

template <typename T>
class T_FSMState 
	: public FSMState
{
public:
	T_FSMState(FiniteStateMachine* pOwner, std::string Name)
		: FSMState(pOwner, Name)
	{
		owner = dynamic_cast<T*>(this->m_pOwner->GetOwner());
	}
protected:
	T* owner;

};