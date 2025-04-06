#include "pch.h"
#include "CDatabase.h"
#include "CGame.h"

int main()
{
	CDatabase::getInstance().Initialize();
	CGame::getInstance().Run();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}