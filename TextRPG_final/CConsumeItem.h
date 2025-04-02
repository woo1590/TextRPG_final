#pragma once
#include "Define.h"
#include "CItem.h"

class CConsumeItem :public CItem
{
private:
	tagItemInfo m_tItemInfo;
public:
	CConsumeItem(tagItemInfo _ItemInfo):m_tItemInfo(_ItemInfo){}
	~CConsumeItem(){}

	void Render()const override;
	std::string getItemType()const override;
	tagItemInfo	getItemInfo()const override;

	void		Use();
};
