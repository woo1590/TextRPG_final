#pragma once
#include "CItem.h"

class CEquipItem :public CItem
{
private:
	tagItemInfo m_tItemInfo;
public:
	CEquipItem(tagItemInfo _ItemInfo):m_tItemInfo(_ItemInfo),CItem(){}
	~CEquipItem(){}

	void Render()const override;
	std::string getItemType()const override;
	tagItemInfo	getItemInfo()const override;

};