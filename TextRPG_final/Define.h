#pragma once
#include <string>

#define SAFE_DEL(x) if(x){delete x; x=nullptr;}

typedef size_t ID;

enum SCENE
{
	SCENE_MAIN = 1,
	SCENE_LOBBY,
	SCENE_INVENTORY,
	SCENE_INFO,
	SCENE_SHOP,
	SCENE_FIELD,
	SCENE_END
};

enum ITEM_TYPE
{
	Default,
	Cousume,
	Equip
};

enum FIGHT_RES
{
	FR_NONE,
	WIN,
	LOSE
};

struct tagMonsterInfo
{
	int m_iID = 0;
	std::string m_sName = "";
	int m_iHP = 0;
	int m_iAttack = 0;
};

struct tagItemInfo
{
	ITEM_TYPE m_Type = Default;
	int m_iID = 0;
	std::string m_sName = "";
	int m_iAttack = 0;
	int m_iHealAmount = 0;
};
