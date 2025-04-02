#include "pch.h"
#include "CEquipItem.h"

void CEquipItem::Render() const
{
	cout << '[' << m_tItemInfo.m_sName << ']' << endl;
}

std::string CEquipItem::getItemType() const
{
	return m_tItemInfo.m_sItemType;
}

tagItemInfo CEquipItem::getItemInfo() const
{
	return m_tItemInfo;
}

