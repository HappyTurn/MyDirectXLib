#include "CDirectXLib.h"

LPDIRECT3DDEVICE9 GetDevice(void);
void printMessage(char* str);

class CCamera : public CDirectXLib {

public:
	CCamera();
	~CCamera();
	void view();
	void updateLocation(D3DXVECTOR3 vec);
	void setLocation(D3DXVECTOR3 vec);
	void setLookAt(D3DXVECTOR3 vec);
	void updateLookAt(D3DXVECTOR3 vec);
	//ÉJÉÅÉâÇÃè„ï˚å¸ÇéwíË
	void updateUpDir(D3DXVECTOR3 vec);
	void setUpDir(D3DXVECTOR3 vec);

private:
	D3DXVECTOR3 _location;
	D3DXVECTOR3 _lookAt;
	D3DXVECTOR3 _upDir;
	D3DXMATRIXA16 _matView;
};