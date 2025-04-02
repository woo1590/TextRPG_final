#include "pch.h"
#include "CConsumeItem.h"
#include "CGame.h"
#include "CPlayer.h"

void CConsumeItem::Render() const
{
	cout << '[' << m_tItemInfo.m_sName << ']' << endl;
	cout << "È¸º¹·® : " << m_tItemInfo.m_iHealAmount << endl;
}

std::string CConsumeItem::getItemType() const
{
	return m_tItemInfo.m_sItemType;
}

tagItemInfo CConsumeItem::getItemInfo() const
{
	return m_tItemInfo;
}

void CConsumeItem::Use()
{
	CGame::getInstance().getPlayer()->setHP(m_tItemInfo.m_iHealAmount);
}



