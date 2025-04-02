#pragma once
#include <vector>

class CItem;
class CItemSlot;
class CInventory
{
private:
	std::vector<CItemSlot*> m_vecConsumeInven;
public:
	CInventory() {}
	~CInventory() { Release(); }

	void	Initialize();
	void	Release();
	void	Render();

	CItemSlot* getEmptySlot();
	void	addItem(CItem* _pItem, int _iAmount);
	void	useItem(CItemSlot* _pItemSlot);
};