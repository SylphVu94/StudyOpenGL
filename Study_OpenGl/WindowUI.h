#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>

class WindowUI
{
	public:
	WindowUI(void);
	WindowUI(HINSTANCE hInstance);
	virtual ~WindowUI(void);

	//Main application loop
	int Run();

	//Framework methods
	virtual bool Init();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
	HWND      m_hAppWnd;
	HINSTANCE m_hAppInstance;
	HDC       m_hDevContext;
	HGLRC     m_hGLRenderContext;
	UINT	  m_ClientWidth;
	UINT	  m_ClientHeight;
	DWORD	  m_WindowStyle;
	char*     m_AppTitle;
	float     m_FPS;

	protected:
	//Initilize Window
	bool InitWindow();
	//Initilize OpenGL
	bool InitGL();
	//Calculate frames per second
	void CalculateFPS(float dt);
	//Shutdown OpenGl
	void ShutdownGl();

};
#endif // !WINDOW_H
