#pragma once

class InputManager
{
public:
	bool IsKeyDown(int VKCode) { return GetAsyncKeyState(VKCode) & 0x8000; }
	bool IsKeyUp(int VKCode) { return !(GetAsyncKeyState(VKCode) & 0x8000); }
	bool IsKeyHold(int VKCode) { return (GetAsyncKeyState(VKCode) & 0x8000) != 0; }
};

// ��ü �����
// ���� �Ҿ������ ��
// ���� ���� 
// ���� �Ҵ�

// ������ ����
// ������Ʈ�� ���� -> ������ ������ �� ���� ����� �ȵž־֤���
// ���� �Ҿ������ �ȵ�
// �����Ҵ� -> ���� ���� ���� ���� ���� ���� ���� �������� ������ ���� ��������
// ���� ����ִ� ��ġ�� ����Ŵ