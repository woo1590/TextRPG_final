#pragma once
#include "CScene.h"

class CSceneLobby :public CScene
{
public:
	CSceneLobby() {}
	~CSceneLobby() {}

	void Update();
	void Render();
};