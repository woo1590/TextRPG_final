#include "pch.h"
#include "CDatabase.h"
#include "CGame.h"

int main()
{
	CDatabase::getInstance().Initialize();
	CGame::getInstance().Run();
	return 0;
}