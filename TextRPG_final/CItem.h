#pragma once
#include <string>
#include "Define.h"
class CItem
{
public:
	CItem(){}
	virtual~CItem(){}

	virtual void Render()const = 0;
	virtual std::string getItemType()const = 0;
	virtual tagItemInfo	getItemInfo()const = 0;
};