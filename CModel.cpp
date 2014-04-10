#include "CModel.h"

CModel::CModel(LPCWSTR path) {
	this->_scale = 1.0f;
	D3DXLoadMeshFromX(
		path,
		D3DXMESH_SYSTEMMEM,
		this->getDevice(),
		NULL,
		&_materialBuffer,         // マテリアル情報を指すポインタのアドレス
		NULL,
		&_numOfMat,        // マテリアル数が返ってくる
		&_mesh
		);

	if (_mesh == NULL) {
		std::cout << "X FILE LOAD ERROR" << std::endl;
	}
	else {
		std::cout << "X FILE LODED" << std::endl;
	}
}

CModel::~CModel() {

}


HRESULT CModel::draw() {
	if (this->_mesh == NULL) {
		std::cout << "X FILE DRAW ERROR" << std::endl;
		return E_FAIL;
	}

	D3DXMatrixIdentity(&_modelMatrix);

	// モデルの拡大・縮小を行列に加える
	D3DXMatrixIdentity(&_scaleMatrix);
	D3DXMatrixScaling(&_scaleMatrix, _scale, _scale, _scale);
	_modelMatrix *= _scaleMatrix;

	// モデルの回転を行列に加える
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixRotationYawPitchRoll(&_rotateMatrix, _rotVec.x, _rotVec.y, _rotVec.z);
	_modelMatrix *= _rotateMatrix;

	// モデルの平行移動を行列に加える
	D3DXMatrixIdentity(&_translateMatrix);
	D3DXMatrixTranslation(&_translateMatrix, _posVec.x, _posVec.y, _posVec.z);
	_modelMatrix *= _translateMatrix;

	// ワールド行列に適用
	this->getDevice()->SetTransform(D3DTS_WORLD, &_modelMatrix);

	/*
	D3DXMATERIAL*	d3Mat = (D3DXMATERIAL*)_materialBuffer->GetBufferPointer();
	_material = new D3DMATERIAL9[_numOfMat];
	_texture = new LPDIRECT3DTEXTURE9[_numOfMat];
	for (int i = 0; i < _numOfMat; i++) {
	_material[i] = d3Mat[i].MatD3D;
	_material[i].Ambient = _material[i].Diffuse;// 環境光初期化
	_texture[i] = NULL;	// テクスチャ初期化
	// 使用しているテクスチャがあれば読み込む
	if (d3Mat[i].pTextureFilename != NULL &&
	lstrlen((LPCWSTR)d3Mat[i].pTextureFilename) > 0)
	{
	// テクスチャ読み込み
	if (FAILED(D3DXCreateTextureFromFile(
	this->getDevice(),
	(LPCWSTR)d3Mat[i].pTextureFilename,
	&_texture[i])))
	{
	return E_FAIL;
	}
	}
	}

	_materialBuffer->Release();



	for (int i = 0; i < _numOfMat; i++)
	{
	this->getDevice()->SetMaterial(&_material[i]);	// マテリアル情報をセット
	this->getDevice()->SetTexture(0, _texture[i]);	// テクスチャ情報をセット
	_mesh->DrawSubset(i);	// メッシュを描画
	}
	*/


	this->_mesh->DrawSubset(0);
	return S_OK;
}


void CModel::updateScale(float scale) {
	this->_scale += scale;
}

void CModel::updateRotate(D3DXVECTOR3 vec) {
	this->_rotVec += vec;
}

void CModel::updatePosition(D3DXVECTOR3 vec) {
	this->_posVec += vec;
}

void CModel::setScale(float scale) {
	this->_scale = scale;
}

void CModel::setRotate(D3DXVECTOR3 vec) {
	this->_rotVec = vec;
}

void CModel::setPosition(D3DXVECTOR3 vec) {
	this->_posVec = vec;
}