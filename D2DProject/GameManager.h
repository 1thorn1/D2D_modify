#pragma once
#include <Windows.h>
class VBall;
class Object;
class SPlayer;

class GameManager
{
public:
	// �ּҸ� ���� ������ ����(����)�ϱ� ���� ����Ѵٰ�!!!!!!!!!!!!!
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