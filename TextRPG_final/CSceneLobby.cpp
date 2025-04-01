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
		if (InputValid(iInput, 1, 4))
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
				m_pSceneManager->changeScene(SCENE_INVENTORY);
				return;
			case 4:
				m_pSceneManager->changeScene(SCENE_MAIN);
				return;
			}
		}
	}
}

void CSceneLobby::Render()
{
	cout << "==========" << endl;
	cout << "1. ����" << endl;
	cout << "2. �÷��̾� ����" << endl;
	cout << "3. �κ��丮" << endl;
	cout << "4. ���θ޴�" << endl;
	cout << "==========" << endl;
	cout << "=>";
}
