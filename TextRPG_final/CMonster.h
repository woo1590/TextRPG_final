#pragma once
#include "Define.h"
#include <string>

class CMonster
{
private:
	std::string m_sName;
	int m_iHP;
	int m_iAttack;
	bool m_Alive;
public:
	CMonster(tagMonsterInfo _MonsterInfo);
	~CMonster() {}
	CMonster(const CMonster& _ref);

	void Initialize();
	void Render();

	int		Attack()const;
	void	be_Earned(int _iDamage);
	bool	is_Alive()const;

	std::string getName()const;
};