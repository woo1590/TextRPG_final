#include "pch.h"
#include "CDatabase.h"
#include <fstream>
#include <sstream>

void CDatabase::Initialize()
{
	loadMonster();
}

void CDatabase::loadMonster()
{
	ifstream File("../Data/Monsters.csv");
	if (!File.is_open())
	{
		cout << "파일 열기 실패" << endl;
		exit(-1);
	}

	tagMonsterInfo tTmp;
	string line;
	string sID, sHP, sAttack;

	getline(File, line);
	while (getline(File, line))
	{
		istringstream ss(line);
		getline(ss, sID, ','); tTmp.m_iID = stoi(sID);
		getline(ss, tTmp.m_sName, ',');
		getline(ss, sHP, ','); tTmp.m_iHP = stoi(sHP);
		getline(ss, sAttack, ','); tTmp.m_iAttack = stoi(sAttack);

		m_umMonsterDB[tTmp.m_iID] = tTmp;
	}
	File.close();
}

tagMonsterInfo CDatabase::getMonster(ID _monsterID)
{
	return m_umMonsterDB[_monsterID];
}
