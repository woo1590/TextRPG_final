#pragma once
#include "Define.h"
#include <vector>

class CScene;
class CSceneManager
{
private:
	std::vector<CScene*> m_vecScene;
	SCENE m_CurSceneNum;
public:
	CSceneManager();
	~CSceneManager(){}

	void	Initialize();
	void	Update();
	void	Release();

	void	changeScene(SCENE _SceneNum);
	SCENE	getCurScenenum()const;
	
};
