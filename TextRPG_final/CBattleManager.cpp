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
				//TODO: ������ ���
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
	cout << "1. ����" << endl;
	cout << "2. ������ ���" << endl;
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
	cout << '[' << m_pPlayer->getName() << "]�� ���� !" << endl;
	Sleep(600);
	m_pMonster->be_Earned(m_pPlayer->Attack());
	if (!m_pMonster->is_Alive())
	{
		cout << "�������� Ŭ����" << endl;
		Sleep(600);
		return;
	}
	cout << '[' << m_pMonster->getName() << "]�� ���� !" << endl;
	Sleep(600);
	m_pPlayer->be_Earned(m_pMonster->Attack());
	if (!m_pPlayer->is_Alive())
	{
		cout << "�������� ����" << endl;
		Sleep(600);
		return;
	}
}

