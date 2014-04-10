#pragma once

#include "CDirectXManager.h"

class CModel : public CDirectXManager {
public:
	CModel(LPCWSTR path);
	~CModel();
	HRESULT draw();
	void updateScale(float scale);
	void updateRotate(D3DXVECTOR3 vec);
	void updatePosition(D3DXVECTOR3 vec);

	void setScale(float scale);
	void setRotate(D3DXVECTOR3 vec);
	void setPosition(D3DXVECTOR3 vec);

private:
	float _scale;
	D3DXVECTOR3 _rotVec;
	D3DXVECTOR3 _posVec;

	LPD3DXMESH _mesh;
	DWORD _numOfMat;
	D3DMATERIAL9* _material;
	LPDIRECT3DTEXTURE9* _texture;
	//モデルのマトリクス
	D3DXMATRIXA16 _modelMatrix;
	D3DXMATRIXA16 _scaleMatrix;
	D3DXMATRIXA16 _rotateMatrix;
	D3DXMATRIXA16 _translateMatrix;


	LPD3DXBUFFER _materialBuffer;


};

