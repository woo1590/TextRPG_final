#include "pch.h"
#include "CBattleManager.h"
#include "CMonsterManager.h"
#include "CItemManager.h"
#include "CItem.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CGame.h"
#include "CInventory.h"

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
		cout << "���� �� : " << _iFloor << "F" << endl;
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
				m_pPlayer->getInventory()->Render();
				break;
			}
		}
	}
	delMonster();
	if (m_pPlayer->is_Alive())
	{
		m_pPlayer->setGold(_iFloor * 15);
		checkReward();
		return WIN;
	}
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

void CBattleManager::checkReward()
{
	srand(static_cast<unsigned>(time(NULL)));

	int iInput = 0;
	bool is_Heal = false;
	CItem* pRewardItem = CGame::getInstance().getItemManager()->getItem(rand()%10);

	while (true)
	{
		Clear();
		m_pPlayer->statusRender();
		m_pPlayer->inventoryRender();
		cout << "==========" << endl;
		cout << "1. ü�� ȸ�� (10Gold)" << endl;
		cout << "2."; pRewardItem->Render();
		cout << "3. ���� ��" << endl;
		cout << "==========" << endl;
		cout << "=>";
		cin >> iInput;
		if (InputValid(iInput, 1, 3))
		{
			switch (iInput)
			{
			case 1:
				if (!is_Heal)
				{
					if (m_pPlayer->getGold() >= 10)
					{
						m_pPlayer->setGold(-10);
						m_pPlayer->setHP(10);
						is_Heal = true;
						cout << "ü���� ȸ���Ǿ����ϴ�" << endl;
						Sleep(1000);
						return;
					}
					else
					{
						cout << "��尡 �����մϴ�" << endl;
						Sleep(1000);
					}
				}
				else
				{
					cout << "�̹� ȸ���ϼ̽��ϴ�" << endl;
					Sleep(1000);
				}
				break;
			case 2:
				if (pRewardItem->getItemType() == "Consume")
				{
					m_pPlayer->setInventory(pRewardItem);
				}
				else
				{
					m_pPlayer->equipItem(pRewardItem);
				}
				return;
			case 3:
				return;
			}
		}
	}
}

