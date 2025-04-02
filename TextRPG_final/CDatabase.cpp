#include "pch.h"
#include "CDatabase.h"
#include <fstream>
#include <sstream>

void CDatabase::Initialize()
{
	loadMonster();
	loadItem();
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

void CDatabase::loadItem()
{
	ifstream File("../Data/Items.csv");
	if (!File.is_open())
	{
		cout << "파일 열기 실패" << endl;
		exit(-1);
	}

	string line;
	string sID, sAttack, sDefence, sIncreaseMaxHP, sHealAmount;
	getline(File, line);

	while (getline(File, line))
	{
		tagItemInfo tTmp;
		istringstream ss(line);
		getline(ss, sID, ','); tTmp.m_iID = stoi(sID);
		getline(ss, tTmp.m_sName, ',');
		getline(ss, tTmp.m_sItemType, ',');
		getline(ss, sAttack, ','); tTmp.m_iAttack = stoi(sAttack);
		getline(ss, sDefence, ','); tTmp.m_iDefence = stoi(sDefence);
		getline(ss, sIncreaseMaxHP, ','); tTmp.m_iIncreaseMaxHP = stoi(sIncreaseMaxHP);
		getline(ss, sHealAmount, ','); tTmp.m_iHealAmount = stoi(sHealAmount);

		m_umItemDB[tTmp.m_iID] = tTmp;
	}
	File.close();
}

tagMonsterInfo CDatabase::getMonster(ID _monsterID)
{
	return m_umMonsterDB[_monsterID];
}

tagItemInfo CDatabase::getItem(ID _itemID)
{
	return m_umItemDB[_itemID];
}
