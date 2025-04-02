#include "pch.h"
#include "CFieldScene.h"
#include "CBattleManager.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CGame.h"

CFieldScene::CFieldScene():m_upBattleManager(nullptr)
{
	m_upBattleManager = make_unique<CBattleManager>();
	m_upBattleManager->Initialize();
}

void CFieldScene::Update()
{
	int iInput = 0;
	int iFloor = 1;
	FIGHT_RES eRes = FR_NONE;
	while (true)
	{
		Clear();
		if (iFloor > 10)
		{
			cout << "==========" << endl;
			cout << "던전 완료" << endl;
			cout << "==========" << endl;
			Sleep(1000);
			m_pSceneManager->changeScene(SCENE_LOBBY);
			CGame::getInstance().getPlayer()->is_DeadInit();
			return;
		}

		eRes = m_upBattleManager->Update(iFloor);
		if (eRes == WIN)
		{
			++iFloor;
			eRes = FR_NONE;
		}
		else
		{
			m_pSceneManager->changeScene(SCENE_LOBBY);
			CGame::getInstance().getPlayer()->is_DeadInit();
			return;
		}
	}
}

void CFieldScene::Render()
{

}


