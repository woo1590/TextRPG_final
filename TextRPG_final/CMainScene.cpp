#include "pch.h"
#include "CMainScene.h"

void CMainScene::Update()
{
	int iInput = 0;
	while (true)
	{
		Clear();
		Render();
		cin >> iInput;
		if (InputValid(iInput, 1, 2))
		{
			switch (iInput)
			{
			case 1:
				m_pSceneManager->changeScene(SCENE_LOBBY);
				return;
			case 2:
				m_pSceneManager->changeScene(SCENE_END);
				return;
			}
		}
	}
}

void CMainScene::Render()
{
	cout << "==========" << endl;
	cout << "1. ���ӽ���" << endl;
	cout << "2. ��������" << endl;
	cout << "==========" << endl;
	cout << "=>";
}
