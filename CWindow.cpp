#include "CWindow.h"


CWindow::CWindow() {

}

CWindow::~CWindow() {
	UnregisterClass(_name, _wc.hInstance);
}


void CWindow::createWindow(LPCWSTR name, int width, int height) {

	this->_name = name;

	_wc.cbSize = sizeof(_wc);
	_wc.style = CS_CLASSDC;
	_wc.lpfnWndProc = WndProc;
	_wc.cbClsExtra = 0;                    // 拡張情報１
	_wc.cbWndExtra = 0;                    // 拡張情報２
	_wc.hInstance = _hInst;                 // インスタンスハンドル
	_wc.hIcon = NULL;          // アイコン
	_wc.hIconSm = NULL;
	_wc.hCursor = NULL;
	_wc.hbrBackground = NULL;
	_wc.lpszMenuName = NULL;
	_wc.lpszClassName = _name;
	RegisterClassEx(&_wc);

	_hWnd = CreateWindow(
		_wc.lpszClassName,
		_name,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		width,
		height,
		NULL,
		NULL,
		_hInst,
		NULL
		);

	ShowWindow(_hWnd, SW_SHOW);
	UpdateWindow(_hWnd);

}

LRESULT CALLBACK CWindow::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:

		break;
	}



	return DefWindowProc(hWnd, msg, wParam, lParam);
}

HWND CWindow::getWindowHandle() {
	return _hWnd;
}

void CWindow::show() {
	ShowWindow(_hWnd, SW_SHOW);
	UpdateWindow(_hWnd);
}