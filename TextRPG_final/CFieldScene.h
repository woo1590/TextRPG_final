#pragma once
#include "CScene.h"
#include "CBattleManager.h"

#include <memory>

class CFieldScene:public CScene
{
private:
	std::unique_ptr<CBattleManager> m_upBattleManager;
public:
	CFieldScene();
	~CFieldScene(){}

	void Update();
	void Render();


};