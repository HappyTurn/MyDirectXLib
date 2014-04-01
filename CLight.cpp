#include "CLight.h"

int CLight::index = 0;

CLight::CLight() {
	CDirectXLib();
	ZeroMemory(&this->_light, sizeof(D3DLIGHT9));
	// デフォルト設定
	this->_light.Type = D3DLIGHT_DIRECTIONAL;
	this->_light.Diffuse.r = 1.0f;
	this->_light.Diffuse.g = 1.0f;
	this->_light.Diffuse.b = 1.0f;
	D3DXVECTOR3 defaultVec = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	this->_dir = defaultVec;
	D3DXVec3Normalize((D3DXVECTOR3*)&this->_light.Direction, &this->_dir);
	this->_light.Range = 1000.0f;
	this->_id = this->index;
	this->index++;
	this->getDevice()->LightEnable(this->_id, TRUE);
	std::cout << this->_id << std::endl;

}

CLight::~CLight() {

}

void CLight::light() {
	this->getDevice()->SetLight(this->_id, &_light);
	this->getDevice()->SetRenderState(D3DRS_LIGHTING, TRUE);
	this->getDevice()->SetRenderState(D3DRS_AMBIENT, 0x00202020);
}

void CLight::setLightType(D3DLIGHTTYPE type) {
	this->_light.Type = type;
}

void CLight::setDir(D3DXVECTOR3 vec) {
	this->_dir = vec;
	D3DXVec3Normalize((D3DXVECTOR3*)&_light.Direction, &_dir);
}

void CLight::updateDir(D3DXVECTOR3 vec) {
	this->_dir += vec;
	D3DXVec3Normalize((D3DXVECTOR3*)&_light.Direction, &_dir);
}

void CLight::setRange(float range) {
	this->_light.Range = range;
}

void CLight::turnOn() {
	this->getDevice()->LightEnable(this->_id, TRUE);
}

void CLight::turnOff() {
	this->getDevice()->LightEnable(this->_id, FALSE);
}