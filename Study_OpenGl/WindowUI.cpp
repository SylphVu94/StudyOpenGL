#include "WindowUI.h"

namespace {
	WindowUI* g_Uiwindow = NULL;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, WPARAM lParam)
{
	if (g_Uiwindow)
		return g_Uiwindow->MsgProc(hwnd, msg, wParam, lParam);
	else
		return DefWindowProc(hwnd, msg, wParam, lParam);
}

WindowUI::WindowUI(void)
{

}

WindowUI::WindowUI(HINSTANCE hInstance)
{
	m_hAppInstance = hInstance;
	m_hAppWnd = NULL;
	m_hDevContext = NULL;
	m_ClientHeight = 800;
	m_ClientWidth = 600;
	m_AppTitle = "OpenGL Application";
	m_WindowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX;
	m_FPS = 0.0f;
	g_Uiwindow = this;
}

WindowUI::~WindowUI()
{

}

int WindowUI::Run()
{
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Update(0.0f);
			Render();
			CalculateFPS(0.0f);
		}

		ShutdownGl();

		return static_cast<int>(msg.wParam);
	}
}

bool WindowUI::InitWindow()
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hInstance = m_hAppInstance;
	wcex.lpfnWndProc = MainWndProc;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject((NULL_BRUSH);
	wcex.lpszClassName = "GLAPPWNDCLASS";
	wcex.lpszMenuName = NULL;
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx())
} 

LRESULT WindowUI::MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0; 
	default:
		break;
	}
}