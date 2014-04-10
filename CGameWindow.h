#pragma once

#include "CDirectXManager.h"
#include "CWindow.h"

class CGameWindow : public CWindow, public CDirectXManager {
public:
	CGameWindow();
	~CGameWindow();
	void createWindow(LPCWSTR name, int width, int height);
private:

};