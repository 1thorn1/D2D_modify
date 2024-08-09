#pragma once
#include "Component.h"
#include "MathHelper.h"

class Scene : public Component
{
public:
	Scene();
	virtual ~Scene();

	Scene* m_pParentScene = nullptr;

	Vector2F m_RelativeScale = { 1,1 }; 	 // 상대 크기
	float		   m_RelativeRotation = 0;		 // 상대 회전
	Vector2F m_RelativeLocation = { 0,0 }; // 상대 위치

	D2D1_MATRIX_3X2_F m_RelativeTransform;		// 상대 복합 변환
	D2D1_MATRIX_3X2_F m_WorldTransform;			// 부모 반영 최종 변환

	void UpdateTransform();
	void SetParent(Scene* pParentScene) { m_pParentScene = pParentScene; }

	Vector2F GetWorldLocation()
	{
		Vector2F out;
		out.x = m_WorldTransform._31;
		out.y = m_WorldTransform._32;
		return out;
	}

	virtual void Update();
	virtual void Render();
};

