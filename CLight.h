#pragma once

#include "CDirectXLib.h"

LPDIRECT3DDEVICE9 GetDevice(void);
void printMessage(char* str);

class CLight : public CDirectXLib {

public:
	CLight();
	~CLight();
	void light();
	void setLightType(D3DLIGHTTYPE type);
	void updateDir(D3DXVECTOR3 vec);
	void setDir(D3DXVECTOR3 vec);
	void setRange(float range);
	void turnOn();
	void turnOff();

private:
	D3DXVECTOR3 _dir;
	D3DLIGHT9 _light;
	D3DLIGHTTYPE _type;
	int _id;
	bool _isLight;

	static int index;
};