#include "pch.h"
#include "CMonster.h"

CMonster::CMonster(tagMonsterInfo _MonsterInfo)
{
	m_sName = _MonsterInfo.m_sName;
	m_iHP = _MonsterInfo.m_iHP;
	m_iAttack = _MonsterInfo.m_iAttack;
	m_Alive = true;
}

CMonster::CMonster(const CMonster& _ref)
{
	m_sName = _ref.m_sName;
	m_iHP = _ref.m_iHP;
	m_iAttack = _ref.m_iAttack;
	m_Alive = _ref.m_Alive;
}

void CMonster::Initialize()
{

}

void CMonster::Render()
{
	cout << "==========" << endl;
	cout << '[' << m_sName << ']' << endl;
	cout << "HP : " << m_iHP << endl;
	cout << "Attack : " << m_iAttack << endl;
}

int CMonster::Attack() const
{
	return m_iAttack;
}

void CMonster::be_Earned(int _iDamage)
{
	m_iHP -= _iDamage;
	if (m_iHP <= 0)
	{
		m_iHP = 0;
		m_Alive = false;
	}
}

bool CMonster::is_Alive() const
{
	return m_Alive;
}

std::string CMonster::getName() const
{
	return m_sName;
}
