#include "pch.h"
#include "CSceneManager.h"
#include "CScene.h"
#include "CMainScene.h"
#include "CFieldScene.h"
#include "CInfoScene.h"
#include "CSceneLobby.h"


CSceneManager::CSceneManager()
{
	m_vecScene.resize(static_cast<size_t> (SCENE_END));
	m_CurSceneNum = SCENE_MAIN;
}

void CSceneManager::Initialize()
{
	m_vecScene[SCENE_MAIN] = new CMainScene;
	m_vecScene[SCENE_LOBBY] = new CSceneLobby;
	m_vecScene[SCENE_INFO] = new CInfoScene;
	m_vecScene[SCENE_FIELD] = new CFieldScene;
	//TODO : 인벤토리씬 추가, 상점..?은 모르겠음
}

void CSceneManager::Update()
{
	m_vecScene[static_cast<size_t>(m_CurSceneNum)]->Update();
}

void CSceneManager::Release()
{
	for (auto& scene : m_vecScene)
	{
		Safe_Delete<CScene*>(scene);
	}
	m_vecScene.clear();
}

void CSceneManager::changeScene(SCENE _SceneNum)
{

	m_CurSceneNum = _SceneNum;
	
}

SCENE CSceneManager::getCurScenenum()const
{
	return m_CurSceneNum;
}


