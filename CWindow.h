#pragma once

#include <windows.h>

class CWindow {
public:
	CWindow();
	~CWindow();
	void  createWindow(LPCWSTR name, int width, int height);
	void show();
	HWND getWindowHandle();
private:
	HWND _hWnd;
	HINSTANCE _hInst;
	HINSTANCE _hPrevInst;
	LPSTR _lpCmdLine;
	int _nCmdShow;
	WNDCLASSEX _wc;
	LPCWSTR _name;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};