//#pragma once
//#include "DemoApp.h"
//#include "Enemy.h"
//#include "FPlayer.h"
//
//class IEnemyState
//	: public T_FSMState<Enemy>
//{
//
//public:
//	IEnemyState(FiniteStateMachine* pOwner, std::string Name) : T_FSMState(pOwner, Name) {}
//	virtual void Initialize()
//	{
//		//owner = dynamic_cast<Enemy*>(this->m_pOwner->GetOwner());
//	}
//	virtual void Enter() = 0;
//	virtual void Update() = 0;
//	virtual void Exit() = 0;
//};