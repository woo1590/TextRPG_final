#include "pch.h"
#include "CInfoScene.h"
#include "CSceneManager.h"
#include "CGame.h"
#include "CPlayer.h"

CInfoScene::CInfoScene():m_pPlayer(nullptr)
{
	m_pPlayer=CGame::getInstance().getPlayer();
}

void CInfoScene::Update()
{
	int iInput = 0;
	while (true)
	{
		Render();
		cin >> iInput;
		if (InputValid(iInput, 0, 0))
		{
			m_pSceneManager->changeScene(SCENE_LOBBY);
			return;
		}
	}
}

void CInfoScene::Render()
{
	m_pPlayer->statusRender();
	m_pPlayer->inventoryRender();
	cout << "(³ª°¡±â 0 ) : ";
}
