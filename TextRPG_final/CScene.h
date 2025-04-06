#pragma once
#include "CGame.h"

class CSceneManager;
class CScene
{
protected:
	//�÷��̾ �ʿ��� ���� �÷��̾ �־������, ���� �̱������� ���������� ����
	 CSceneManager* const m_pSceneManager;
public:
	CScene() :m_pSceneManager(CGame::getInstance().getSceneManager()) {}
	virtual~CScene(){}

	virtual void Update() = 0;
	virtual void Render() = 0;
};