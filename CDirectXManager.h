#pragma once

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

#include <d3dx9.h>
#include <windows.h>
#include <iostream>

class CDirectXManager {
public:
	HRESULT initDirectX(HWND hWnd);
	void initMatrices();
	static LPDIRECT3DDEVICE9 getDevice();
private:
	LPDIRECT3D9 _direct3d9;
	static LPDIRECT3DDEVICE9 _device;
};