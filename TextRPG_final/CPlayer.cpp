#include "pch.h"
#include "CPlayer.h"

void CPlayer::Initialize()
{
	m_iHP = 50;
	m_iMaxHP = 50;
	m_iAttack = 5;
	selectJob();
}

void CPlayer::statusRender()
{
	cout << "==========" << endl;
	cout << '[' << m_sName << ']' << endl;
	cout << "HP : " << m_iHP << endl;
	cout << "Attack : " << m_iAttack << endl;
}

void CPlayer::inventoryRender()
{
	//TODO: 인벤토리 출력
}

void CPlayer::selectJob()
{
	int iInput = 0;
	while (true)
	{
		cout << "==========" << endl;
		cout << "1. 전사" << endl;
		cout << "2. 마법사" << endl;
		cout << "3. 도적" << endl;
		cout << "==========" << endl;
		cout << "=>";
		cin >> iInput;
		if (InputValid(iInput, 1, 3))
		{
			switch (iInput)
			{
			case 1:
				m_sName = "전사";
				return;
			case 2:
				m_sName = "마법사";
				return;
			case 3:
				m_sName = "도적";
				return;
			}
		}
	}
}

int CPlayer::Attack() const
{
	return m_iAttack;
}

void CPlayer::be_Earned(int _iDamage)
{
	m_iHP -= m_iAttack;
	if (m_iHP <= 0)
	{
		m_iHP = 0;
		m_Alive = false;
	}
}

bool CPlayer::is_Alive() const
{
	return m_Alive;
}

std::string CPlayer::getName() const
{
	return m_sName;
}

void CPlayer::Release()
{
	//
}
