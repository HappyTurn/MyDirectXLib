#include "CDirectXManager.h"


LPDIRECT3DDEVICE9 CDirectXManager::_device;

HRESULT CDirectXManager::initDirectX(HWND hWnd) {
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
	if (FAILED(_direct3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &_device)))
	{
		return E_FAIL;
	}

	// Turn off culling
	_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	// Turn on the zbuffer
	_device->SetRenderState(D3DRS_ZENABLE, TRUE);

	//マトリクス初期化
	initMatrices();

	return S_OK;
}

void CDirectXManager::initMatrices() {
	// Set up world matrix
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	this->getDevice()->SetTransform(D3DTS_WORLD, &matWorld);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	this->getDevice()->SetTransform(D3DTS_PROJECTION, &matProj);
}

LPDIRECT3DDEVICE9 CDirectXManager::getDevice() {
	return _device;
}