#pragma once

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

#include <d3dx9.h>
#include <windows.h>
#include <iostream>

LPDIRECT3DDEVICE9 GetDevice(void);

class CDirectXLib {

public:
	CDirectXLib();
	LPDIRECT3DDEVICE9 getDevice();
private:
	LPDIRECT3DDEVICE9 _device;

};