#pragma once

class CPlayer;
class CMonster;
class CBattleManager
{
private:
	CPlayer* m_pPlayer;
	CMonster* m_pMonster;
public:
	CBattleManager():m_pPlayer(nullptr), m_pMonster(nullptr){}
	~CBattleManager(){}

	void		Initialize();
	FIGHT_RES	Update(int _iFloor);
	void		Render();

	void		createMonster(int _iIdx);
	void		delMonster();
	void		Battle();
	void		checkReward();
};