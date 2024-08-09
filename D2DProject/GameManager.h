#pragma once
#include <Windows.h>
class VBall;
class Object;
class SPlayer;

class GameManager
{
public:
	// 주소를 통해 정보를 저장(접근)하기 위해 사용한다고!!!!!!!!!!!!!
	static SPlayer* p1;
	static SPlayer* p2;
	static Object* wall;
};

struct CustomInput
{
	int up = VK_UP;
	int down = VK_DOWN;
	int left = VK_LEFT;
	int right = VK_RIGHT;
	int enter = VK_RETURN;

	int start = VK_F1;
};