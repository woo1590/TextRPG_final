#pragma once
#include <vector>

class CItem;
class CItemManager
{
private:
	std::vector<CItem*> m_vecItems;
	size_t m_iItemAmount;
public:
	CItemManager(size_t _iAmount);
	~CItemManager(){}

	void		Initialize();
	CItem*		getItem(int _iNum);
	void		Release();
};