#include "pch.h"
#include "CPlayer.h"
#include "CItem.h"
#include "CItemSlot.h"
#include "CInventory.h"
#include "CUtility.h"
#include "CDatabase.h"
#include "Define.h"

void CPlayer::Initialize()
{
	m_iHP = 50;
	m_iMaxHP = 50;
	m_iAttack = 999;
	m_iDefence = 5;
	selectJob();

	m_pInventory = new CInventory;
	m_pInventory->Initialize();

	m_vecItemSlot.reserve(2);
	for (int i = 0; i < 2; ++i)
	{
		m_vecItemSlot.push_back(new CItemSlot);
	}
}

void CPlayer::statusRender()
{
	cout << "==========" << endl;
	cout << '[' << m_sName << ']' << endl;
	cout << "HP : " << m_iHP << endl;
	cout << "Attack : " << m_iAttack << endl;
	cout << "Defence : " << m_iDefence << endl;
}

void CPlayer::inventoryRender()
{
	
	for (vector<CItemSlot*>::iterator iter = m_vecItemSlot.begin();
		iter != m_vecItemSlot.end(); ++iter)
	{
		cout << "==========" << endl;
		(*iter)->Render();
		cout << "==========" << endl;
	}
	cout << "소지금 : " << m_iGold << endl;
	
}

void CPlayer::selectJob()
{
	int iInput = 0;
	while (true)
	{
		cout << "==========" << endl;
		cout << "1. 전사" << endl;
		cout << "2. 마법사" << endl;
		cout << "3. 도적" << endl;
		cout << "==========" << endl;
		cout << "=>";
		cin >> iInput;
		if (InputValid(iInput, 1, 3))
		{
			switch (iInput)
			{
			case 1:
				m_sName = "전사";
				return;
			case 2:
				m_sName = "마법사";
				return;
			case 3:
				m_sName = "도적";
				return;
			}
		}
	}
}

void CPlayer::setHP(int _iHealAmount)
{
	m_iHP += _iHealAmount;
	if (m_iHP > m_iMaxHP) m_iHP = m_iMaxHP;
}

int CPlayer::getHP() const
{
	return m_iHP;
}

int CPlayer::getGold() const
{
	return m_iGold;
}

void CPlayer::setGold(int _iGold)
{
	m_iGold += _iGold;
}

void CPlayer::equipItem(CItem* _pItem)
{
	int iInput = 0;
	while (true)
	{
		if (getEmptySlot())
		{
			getEmptySlot()->setItem(_pItem);
			addStatus(_pItem);
			cout << "아이템 착용 성공" << endl;
			Sleep(1000);
			break;
		}
		else
		{
			cout << "빈 슬롯이 없습니다" << endl;
			cout << "아이템을 교체 하시겠습니까?" << endl;
			cout << "1. 교체" << endl;
			cout << "2. 취소" << endl;
			cout << "=>";
			cin >> iInput;
			if (InputValid(iInput, 1, 2))
			{
				switch (iInput)
				{
				case 1:
					removeItem();
					break;
				case 2:
					return;
				}
			}
		}
	}
}

void CPlayer::removeItem()
{
	int iInput = 0;
	while (true)
	{
		Clear();
		cout << "제거 할 아이템을 선택 해주세요" << endl;
		inventoryRender();
		cout << "=>";
		cin >> iInput;
		if (InputValid(iInput, 1, 2))
		{
			if (iInput)
			{
				removeStatus(m_vecItemSlot[iInput - 1]->getItem());
				m_vecItemSlot[iInput - 1]->initSlot();
			}	
			break;
		}
	}
}

CItemSlot* CPlayer::getEmptySlot()
{
	vector<CItemSlot*>::iterator iter = find_if(m_vecItemSlot.begin(), m_vecItemSlot.end(), [](CItemSlot* _pSlot)
		{
			return !_pSlot->getItem();
		});

	if (iter != m_vecItemSlot.end()) return *iter;
	else return nullptr;
}

void CPlayer::setInventory(CItem* _pItem, int _iAmount)
{
	m_pInventory->addItem(_pItem, _iAmount);
}

CInventory* CPlayer::getInventory() const
{
	return m_pInventory;
}

void CPlayer::removeStatus(CItem* _pItemInfo)
{
	tagItemInfo tTmp = _pItemInfo->getItemInfo();

	m_iAttack -= tTmp.m_iAttack;
	m_iDefence -= tTmp.m_iDefence;
	m_iMaxHP -= tTmp.m_iIncreaseMaxHP;
	if(m_iHP>m_iMaxHP) m_iHP = m_iMaxHP;
}

void CPlayer::addStatus(CItem* _pItemInfo)
{
	tagItemInfo tTmp = _pItemInfo->getItemInfo();

	m_iAttack += tTmp.m_iAttack;
	m_iDefence += tTmp.m_iDefence;
	m_iMaxHP += tTmp.m_iIncreaseMaxHP;
}

int CPlayer::Attack() const
{
	return m_iAttack;
}

void CPlayer::be_Earned(int _iDamage)
{
	m_iHP -=CUtility::calculateAttack(_iDamage,m_iDefence);
	if (m_iHP <= 0)
	{
		m_iHP = 0;
		m_Alive = false;
	}
}

bool CPlayer::is_Alive() const
{
	return m_Alive;
}

void CPlayer::is_DeadInit()
{
	m_iHP = 50;
	m_iMaxHP = 50;
	m_iAttack = 5;
	m_iDefence = 5;
	m_Alive = true;

	for (auto& slot: m_vecItemSlot)
	{
		(*slot).initSlot();
	}
}

std::string CPlayer::getName() const
{
	return m_sName;
}

void CPlayer::Release()
{
	Safe_Delete<CInventory*>(m_pInventory);
	for (vector<CItemSlot*>::iterator iter = m_vecItemSlot.begin();
		iter != m_vecItemSlot.end(); ++iter)
	{
		Safe_Delete<CItemSlot*>(*iter);
	}
	m_vecItemSlot.clear();
}
