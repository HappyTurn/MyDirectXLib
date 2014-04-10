#include "CGameWindow.h"

CGameWindow::CGameWindow() {

}

CGameWindow::~CGameWindow() {
	UnregisterClass(_name, _wc.hInstance);
}

HRESULT CGameWindow::InitDirectX() {
	// Create the D3D object.
	if (NULL == (_direct3d9 = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// Set up the structure used to create the D3DDevice. Since we are now
	// using more complex geometry, we will create a device with a zbuffer.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	// Create the D3DDevice
	if (FAILED(_direct3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &_device)))
	{
		return E_FAIL;
	}

	// Turn off culling
	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	// Turn on the zbuffer
	_device->SetRenderState(D3DRS_ZENABLE, TRUE);

	return S_OK;
}


void CGameWindow::createGameWindow(LPCWSTR name, int width, int height) {

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

LRESULT CALLBACK CGameWindow::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
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

LPDIRECT3DDEVICE9 CGameWindow::getDevice() {
	return _device;
}


void CGameWindow::showWindow() {
	ShowWindow(_hWnd, SW_SHOW);
	UpdateWindow(_hWnd);
}