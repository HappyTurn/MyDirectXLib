#include "CDirectXLib.h"

CDirectXLib::CDirectXLib() {
	_device = GetDevice();
}

LPDIRECT3DDEVICE9 CDirectXLib::getDevice() {
	return _device;
}