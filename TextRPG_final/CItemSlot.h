#pragma once

class CItem;
class CItemSlot
{
private:
	CItem* m_pItemInfo;
	size_t m_iAmount;
public:
	CItemSlot():m_pItemInfo(nullptr),m_iAmount(0) {}
	~CItemSlot() {}

	void setItem(CItem* _pItemInfo);
};