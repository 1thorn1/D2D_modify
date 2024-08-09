#include "pch.h"
#include "AnimationAsset.h"
#include "ResourceManager.h"


bool AnimationAsset::LoadAnimation(std::wstring FilePath)
{
	//�ؽ�Ʈ ������ ��� csv���� ����� �о�´�.
	// �Ʒ� �Լ��� csv������ ó���Ѵ�.
	// �����Q�� CSV ����
	if (FilePath == std::wstring(L"CSV/Attack.txt"))
	{
		LoadAnimationFromCSV(0, L"CSV/Attack.txt");
	}
	if (FilePath == std::wstring(L"CSV/DRun.txt"))
	{
		LoadAnimationFromCSV(1, L"CSV/DRun.txt");
	}
	if (FilePath == std::wstring(L"CSV/Jump.txt"))
	{
		LoadAnimationFromCSV(2, L"CSV/Jump.txt");
	}
	if (FilePath == std::wstring(L"CSV/Idle.txt"))
	{
		LoadAnimationFromCSV(3, L"CSV/Idle.txt");
	}

	// ������Ʈ��
	if (FilePath == std::wstring(L"CSV/flag.txt"))
	{
		LoadAnimationFromCSV(4, L"CSV/flag.txt");
	}
	if (FilePath == std::wstring(L"CSV/DBall.txt"))
	{
		LoadAnimationFromCSV(5, L"CSV/DBall.txt");
	}
	return true;
}


bool AnimationAsset::LoadAnimationFromCSV(int index, const wchar_t* fileName)
{
	std::wifstream file(fileName);
	if (!file.is_open())
	{
		return false;
	}

	std::wstring line;	// �� ���� ���ڿ�
	int FrameCount = 0;	// �������� ����
	{
		std::getline(file, line);	// ù��° �� �б�
		std::wstringstream wss(line);
		wss >> FrameCount;
	}

	m_Animations.resize(15);
	m_Animations[index].Frames.resize(FrameCount);
	for (int i = 0; i < FrameCount; i++)
	{
		std::getline(file, line);	 // ù��° �� �б�
		std::wstringstream wss(line); // �� �� �о wstringstream�� ����
		std::wstring token;
		{
			getline(wss, token, L',');	// wss�� ������ ,�� �������� ���ڿ��� �и�
			m_Animations[index].Frames[i].Source.left = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.top = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.right = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.bottom = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Center.x = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Center.y = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Duration = _wtof(token.c_str());
		}
	}
}
