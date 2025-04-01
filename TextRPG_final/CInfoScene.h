#pragma once
#include "CScene.h"

class CPlayer;
class CInfoScene :public CScene
{
private:
	CPlayer* m_pPlayer;
public:
	CInfoScene();
	~CInfoScene(){}

	void Update();
	void Render();
};