#include "pch.h"
#include "CSceneLobby.h"

void CSceneLobby::Update()
{
	int iInput = 0;
	while (true)
	{
		Clear();
		Render();
		cin >> iInput;
		if (InputValid(iInput, 1, 3))
		{
			switch (iInput)
			{
			case 1:
				m_pSceneManager->changeScene(SCENE_FIELD);
				return;
			case 2:
				m_pSceneManager->changeScene(SCENE_INFO);
				return;
			case 3:
				m_pSceneManager->changeScene(SCENE_MAIN);
				return;
			}
		}
	}
}

void CSceneLobby::Render()
{
	cout << "==========" << endl;
	cout << "1. 던전" << endl;
	cout << "2. 플레이어 정보" << endl;
	cout << "3. 메인메뉴" << endl;
	cout << "==========" << endl;
	cout << "=>";
}
