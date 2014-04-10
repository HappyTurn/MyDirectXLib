#pragma once

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )

#include "CCamera.h"

CCamera::CCamera() {
	//デフォルト設定
	_location = D3DXVECTOR3(0.0f, 1.0f, -5.0f);
	_lookAt = D3DXVECTOR3(0.0f, 0.1f, 0.0f);
	_upDir = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
}

void CCamera::view() {
	D3DXMatrixLookAtLH(&_matView, &_location, &_lookAt, &_upDir);
	this->getDevice()->SetTransform(D3DTS_VIEW, &_matView);
}

void CCamera::updateLocation(D3DXVECTOR3 vec) {
	this->_location += vec;
}

void CCamera::setLocation(D3DXVECTOR3 vec) {
	this->_location = vec;
}

void CCamera::updateLookAt(D3DXVECTOR3 vec) {
	this->_lookAt += vec;
}

void CCamera::setLookAt(D3DXVECTOR3 vec) {
	this->_lookAt = vec;
}

void CCamera::updateUpDir(D3DXVECTOR3 vec) {
	this->_upDir += vec;
}

void CCamera::setUpDir(D3DXVECTOR3 vec) {
	this->_upDir = vec;
}