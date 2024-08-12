#include "pch.h"
#include "GameApp.h"

// 윈도우 창 띄우기,
// 메세지 루프 돌리기
void GameApp::Initialize(HINSTANCE hInstance)
{
	m_hInstance = hInstance;

	InitWindow();
	D2DRender::InitDirect2D(m_hWnd);
    Debug.Get_Console();
}

HWND GameApp::InitWindow()
{
    const TCHAR* appName = TEXT("삑궷쯖 배구");

    // Step 1: Registering the Window Class
    WNDCLASS wndClass;
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = LoadIcon(m_hInstance, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = appName;
    RegisterClass(&wndClass);

    // Step 2: Creating the Window
    RECT rect{ 0, 0, 1024, 600 };
    ::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    // Get the dimensions of the primary monitor
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Calculate the position for centering the window
    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;

    m_hWnd = CreateWindow(appName, appName, WS_OVERLAPPED | WS_SYSMENU,
        posX, posY, windowWidth, windowHeight, NULL, NULL, m_hInstance, NULL);

    ShowWindow(m_hWnd, SW_SHOWNORMAL);
    UpdateWindow(m_hWnd);

    return m_hWnd;
}


void GameApp::Run()
{
    MSG msg;

    // 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Update();
			Render();
		}
	}
}

void GameApp::FixedUpdate()
{
}

void GameApp::Update()
{
    //InputManager temp;
    //if (temp.IsKeyDown(VK_F1))
    //{
    //	Debug.Log("in");
    //	SceneManager::SetActWorld("play");
    //}

    SceneManager::ChangeWorld();
    SceneManager::Update();
}

void GameApp::Render()
{

    D2DRender::GetRenderTarget()->BeginDraw();
    D2DRender::GetRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::GreenYellow));

    SceneManager::Render(); // 씬매니저를 렌더하면 관리하고 있는 씬들을 

    D2DRender::GetRenderTarget()->EndDraw();
}

void GameApp::Uninitialize()
{
}

LRESULT GameApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
