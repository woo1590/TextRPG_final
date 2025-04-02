#include "pch.h"
#include "CItemSlot.h"
#include "CItem.h"

void CItemSlot::setItem(CItem* _pItemInfo, int _iAmount)
{
	m_pItemInfo = _pItemInfo;
	m_iAmount = _iAmount;
}

CItem* CItemSlot::getItem() const
{
	return m_pItemInfo;
}

void CItemSlot::setItemAmount(int _iAmount)
{
	m_iAmount += _iAmount;
	if (!m_iAmount) initSlot();
}

void CItemSlot::initSlot()
{
	m_pItemInfo = nullptr;
	m_iAmount = 0;
}


void CItemSlot::Render() const
{
	if (m_pItemInfo)
	{
		m_pItemInfo->Render();
	}
	else
	{
		cout << "ºó ½½·Ô" << endl;
	}
}
