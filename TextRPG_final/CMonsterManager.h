#pragma once
#include <vector>

class CMonster;
class CMonsterManager
{
private:
	std::vector<CMonster*> m_vecMonsters;
	size_t m_iMonsterAmount;
public:
	CMonsterManager(size_t _iMonsterAmount) :m_iMonsterAmount(_iMonsterAmount) { m_vecMonsters.reserve(m_iMonsterAmount); }
	~CMonsterManager() {}

	void	Initialize();
	void	Release();

	CMonster* getMonster(size_t _iIdx);
};