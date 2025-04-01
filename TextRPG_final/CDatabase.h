#pragma once
#include "Define.h"
#include <unordered_map>

class CDatabase
{
private:
	std::unordered_map<ID, tagMonsterInfo> m_umMonsterDB;

	CDatabase() {}
	~CDatabase(){}
	CDatabase(const CDatabase& _ref) = delete;
	CDatabase& operator=(CDatabase& _ref) = delete;
public:
	static CDatabase& getInstance()
	{
		static CDatabase Instance;
		return Instance;
	}

	void Initialize();

	void loadMonster();

	tagMonsterInfo getMonster(ID _monsterID);
};