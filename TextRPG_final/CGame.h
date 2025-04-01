#pragma once

class CPlayer;
class CSceneManager;
class CMonsterManager;
class CBattleManager;
class CGame
{
private:
	CSceneManager*		m_pSceneManager;
	CMonsterManager*	m_pMonsterManager;
	CPlayer*			m_pPlayer;


	CGame() :m_pSceneManager(nullptr), m_pMonsterManager(nullptr),m_pPlayer(nullptr) {}
	~CGame(){}
	CGame(const CGame& _ref) = delete;
	CGame& operator=(CGame& _ref) = delete;
public:
	void Initialize();
	void Update();
	void Release();
	void Run();

	static CGame& getInstance()
	{
		static CGame Instance;
		return Instance;
	}

	CSceneManager*		getSceneManager();
	CMonsterManager*	getMonsterManager();
	CPlayer*			getPlayer();
};