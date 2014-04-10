#include "CGameWindow.h"

CGameWindow::CGameWindow() {
	
}

void CGameWindow::createWindow(LPCWSTR name, int width, int height) {
	CWindow::createWindow(name, width, height);
	this->initDirectX(this->getWindowHandle());
}