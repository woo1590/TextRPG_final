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
		cout << '[' << iFloor << "F]" << endl;
		cout << "==========" << endl; 
		eRes = m_upBattleManager->Update(iFloor);
		if (eRes == WIN)
		{
			++iFloor;
			eRes = FR_NONE;
		}
		else
		{
			m_pSceneManager->changeScene(SCENE_LOBBY);
			return;
		}
	}
}

void CFieldScene::Render()
{

}
