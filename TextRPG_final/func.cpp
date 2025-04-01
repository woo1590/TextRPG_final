#include "pch.h"
#include "func.h"

void Clear()
{
	system("cls");
}

bool InputValid(int _iInput, int _iMin, int _iMax)
{
	if (cin.fail())
	{
		cout << "잘못된 입력" << endl;
		cin.clear();
		cin.ignore(34367, '\n');
		Sleep(1000);
		return false;
	}
	else if (_iInput<_iMin || _iInput>_iMax)
	{
		cout << "잘못된 입력" << endl;
		Sleep(1000);
		return false;
	}
	else return true;
}

