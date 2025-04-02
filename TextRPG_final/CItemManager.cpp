#include "pch.h"
#include "CConsumeItem.h"
#include "CEquipItem.h"
#include "CItemManager.h"
#include "CDatabase.h"

CItemManager::CItemManager(size_t _iAmount) :m_iItemAmount(_iAmount)
{
	m_vecItems.reserve(m_iItemAmount);
}

void CItemManager::Initialize()
{
	for (int i = 0; i < m_iItemAmount; ++i)
	{
		tagItemInfo tTmp = CDatabase::getInstance().getItem(i + 1);
		if (tTmp.m_sItemType == "Consume")
		{
			m_vecItems.push_back(new CConsumeItem(tTmp));
		}
		else if (tTmp.m_sItemType == "Equipment")
		{
			m_vecItems.push_back(new CEquipItem(tTmp));
		}
	}
}

CItem* CItemManager::getItem(int _iNum)
{
	return m_vecItems[_iNum];
}
