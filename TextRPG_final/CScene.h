#pragma once
#include "CGame.h"
#include "CSceneManager.h"

class CScene
{
protected:
	CSceneManager* m_pSceneManager;
public:
	CScene() :m_pSceneManager(nullptr)
	{
		m_pSceneManager = CGame::getInstance().getSceneManager();
	}
	virtual~CScene(){}

	virtual void Update() = 0;
	virtual void Render() = 0;
};