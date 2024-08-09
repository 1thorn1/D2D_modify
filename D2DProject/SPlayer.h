#pragma once
#include "DemoApp.h"
#include "GameManager.h"

class SPlayer
	: public GameObject
{
	float m_gravityScale;
	float m_jumpForce;
	float m_position;
	float m_velocity;
	float m_speed;

public:

	static Vector2F sp_velocity;
	AnimationScene* SPlayerAni;
	FiniteStateMachine* fsm;

	CustomInput input;

	SPlayer();
	virtual ~SPlayer();

	virtual void Initialize();
	virtual void Update();
	virtual void Render();

	// 읽기 vs 쓰기
	float GetGravityScale() { return m_gravityScale; } 
	void SetGravityScale(float gravityScale) { m_gravityScale = gravityScale; }
	
	float GetJumpForce() { return m_jumpForce; }
	void SetJumpForce(float jumpForce) {  m_jumpForce = jumpForce; }

	float GetPosition() { return m_position; }
	void SetPosition(float position) {  m_position = position; }

	float Getvelocity() { return m_velocity; }
	void Setvelocity(float velocity) {  m_velocity = velocity; }

	float GetSpeed() { return m_speed; }
	void SetSpeed(float speed) {  m_speed = speed; }

};