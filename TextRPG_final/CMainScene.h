#pragma once
#include "CScene.h"

class CMainScene :public CScene
{
public:
	CMainScene() {}
	~CMainScene() {}

	void Update();
	void Render();
};