#include "pch.h"
#include "CGame.h"
#include "CSceneManager.h"
#include "CMonsterManager.h"
#include "CPlayer.h"


void CGame::Initialize()
{
    m_pSceneManager = new CSceneManager;
    m_pMonsterManager = new CMonsterManager(10);
    m_pPlayer = new CPlayer;

    m_pSceneManager->Initialize();
    m_pMonsterManager->Initialize();
    m_pPlayer->Initialize();
}

void CGame::Update()
{
    while (m_pSceneManager->getCurScenenum() != SCENE_END)
    {
        m_pSceneManager->Update();
    }
}

void CGame::Release()
{
    Safe_Delete<CSceneManager*>(m_pSceneManager);
    Safe_Delete<CMonsterManager*>(m_pMonsterManager);
    Safe_Delete<CPlayer*>(m_pPlayer);
}

void CGame::Run()
{
    Initialize();
    Update();
    Release();
}

CSceneManager* CGame::getSceneManager()
{
    return m_pSceneManager;
}

CMonsterManager* CGame::getMonsterManager()
{
    return m_pMonsterManager;
}

CPlayer* CGame::getPlayer()
{
    return m_pPlayer;
}
