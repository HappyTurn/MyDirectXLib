#include "CKeyboard.h"

CKeyboard::CKeyboard(HINSTANCE hInst, HWND hWnd) {
	HRESULT hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&_inputDevice, NULL);
	_inputDevice->CreateDevice(GUID_SysKeyboard, &_keyboardDevice, NULL);
	_keyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	_keyboardDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	_keyboardDevice->Acquire();
}

CKeyboard::~CKeyboard() {

	if (_inputDevice != NULL) {
		_inputDevice->Release();
		_inputDevice = NULL;
	}

	if (_keyboardDevice != NULL) {
		_keyboardDevice->Unacquire();
		_keyboardDevice->Release();
		_keyboardDevice = NULL;
	}

}

bool CKeyboard::isKeydown(int key) {
	char buffer[256];
	int time = timeGetTime();
	_keyboardDevice->GetDeviceState(sizeof(buffer), (void*)&buffer);
	if (buffer[key] & 0x80) {
		return true;
	}
	else {
		return false;
	}
}