#pragma once
#include "CGame.h"

class CSceneManager;
class CScene
{
protected:
	//플레이어가 필요한 씬에 플레이어를 넣어줘야함, 굳이 싱글톤으로 가져오지는 말고
	 CSceneManager* const m_pSceneManager;
public:
	CScene() :m_pSceneManager(CGame::getInstance().getSceneManager()) {}
	virtual~CScene(){}

	virtual void Update() = 0;
	virtual void Render() = 0;
};