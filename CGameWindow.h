#pragma once

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

#include <d3dx9.h>
#include <windows.h>
#include <iostream>


class CGameWindow {

public:
	CGameWindow();
	~CGameWindow();
	HRESULT InitDirectX();
	void  createGameWindow(LPCWSTR name, int width, int height);
	LPDIRECT3DDEVICE9 getDevice();
	void showWindow();

private:
	LPDIRECT3DDEVICE9 _device;
	LPDIRECT3D9 _direct3d9;
	HWND _hWnd;
	HINSTANCE _hInst;
	HINSTANCE _hPrevInst;
	LPSTR _lpCmdLine;
	int _nCmdShow;
	WNDCLASSEX _wc;
	LPCWSTR _name;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};