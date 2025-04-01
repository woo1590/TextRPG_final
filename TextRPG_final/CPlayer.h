#pragma once
#include <string>
class CPlayer
{
private:
	std::string m_sName;
	int m_iHP;
	int m_iMaxHP;
	int m_iAttack;
	bool m_Alive;
public:
	CPlayer():m_sName(""),m_iHP(0),m_iMaxHP(0),m_iAttack(0),m_Alive(true){}
	~CPlayer() {}

	void Initialize();
	void Release();

	void	statusRender();
	void	inventoryRender();
	void	selectJob();

	int		Attack()const;
	void	be_Earned(int _iDamage);
	bool	is_Alive()const;

	std::string	getName()const;
};