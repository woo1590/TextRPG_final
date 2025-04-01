#include "pch.h"
#include "CMonsterManager.h"
#include "CMonster.h"
#include "CDatabase.h"

void CMonsterManager::Initialize()
{
	for (int i = 0; i < m_iMonsterAmount; ++i)
	{
		tagMonsterInfo tTmp = CDatabase::getInstance().getMonster(i + 1);
		m_vecMonsters.push_back(new CMonster(tTmp));
	}
}

void CMonsterManager::Release()
{
	for (auto& ele : m_vecMonsters)
	{
		Safe_Delete<CMonster*>(ele);
	}
	m_vecMonsters.clear();
}

CMonster* CMonsterManager::getMonster(size_t _iIdx)
{
	if (_iIdx >= m_vecMonsters.size()) return nullptr;
	
	return m_vecMonsters[_iIdx];
}
