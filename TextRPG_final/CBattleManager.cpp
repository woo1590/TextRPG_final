#include "pch.h"
#include "CBattleManager.h"
#include "CMonsterManager.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CGame.h"

void CBattleManager::Initialize()
{
	m_pPlayer = CGame::getInstance().getPlayer();
}

FIGHT_RES CBattleManager::Update(int _iFloor)
{
	createMonster(_iFloor-1);
	int iInput = 0;
	while (m_pPlayer->is_Alive() && m_pMonster->is_Alive())
	{
		Clear();
		m_pPlayer->statusRender();
		m_pMonster->Render();
		Render();
		cin >> iInput;
		if (InputValid(iInput, 1, 2))
		{
			switch (iInput)
			{
			case 1:
				Battle();
				break;
			case 2:
				//TODO: 아이템 사용
				break;
			}
		}
	}
	delMonster();
	if (m_pPlayer->is_Alive()) return WIN;
	else return LOSE;
}

void CBattleManager::Render()
{
	cout << "==========" << endl;
	cout << "1. 공격" << endl;
	cout << "2. 아이템 사용" << endl;
	cout << "==========" << endl;
	cout << "=>";
}

void CBattleManager::createMonster(int _iIdx)
{
	m_pMonster = new CMonster(*(CGame::getInstance().getMonsterManager()->getMonster(_iIdx)));
}

void CBattleManager::delMonster()
{
	Safe_Delete<CMonster*>(m_pMonster);
}

void CBattleManager::Battle()
{
	cout << '[' << m_pPlayer->getName() << "]의 공격 !" << endl;
	Sleep(600);
	m_pMonster->be_Earned(m_pPlayer->Attack());
	if (!m_pMonster->is_Alive())
	{
		cout << "스테이지 클리어" << endl;
		Sleep(600);
		return;
	}
	cout << '[' << m_pMonster->getName() << "]의 공격 !" << endl;
	Sleep(600);
	m_pPlayer->be_Earned(m_pMonster->Attack());
	if (!m_pPlayer->is_Alive())
	{
		cout << "스테이지 실패" << endl;
		Sleep(600);
		return;
	}
}

