#pragma once
#include <string>
#include <vector>

class CItem;
class CItemSlot;
class CInventory;
class CPlayer
{
private:
	std::string m_sName;
	int m_iHP;
	int m_iMaxHP;
	int m_iAttack;
	int m_iDefence;
	int m_iGold;
	bool m_Alive;
	CInventory* m_pInventory;
	std::vector<CItemSlot*> m_vecItemSlot;
public:
	CPlayer():m_sName(""),m_iHP(0),m_iMaxHP(0),m_iAttack(0),m_iDefence(0),
			  m_iGold(0), m_Alive(true),m_pInventory(nullptr){}
	~CPlayer() {}

	void	Initialize();
	void	Release();

	void	statusRender();
	void	inventoryRender();
	void	selectJob();

	void	setHP(int _iHealAmount);
	int		getHP()const;
	int		getGold()const;
	void	setGold(int _iGold);

	void		equipItem(CItem* _pItem);
	void		removeItem();
	CItemSlot*	getEmptySlot();
	void		setInventory(CItem* _pItem, int _iAmount = 1);
	CInventory*	getInventory()const;

	void	removeStatus(CItem* _pItemInfo);
	void	addStatus(CItem* _pItemInfo);

	int		Attack()const;
	void	be_Earned(int _iDamage);
	bool	is_Alive()const;
	void	is_DeadInit();

	std::string	getName()const;
};