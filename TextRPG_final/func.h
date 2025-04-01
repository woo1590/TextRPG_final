#pragma once


void Clear();
bool InputValid(int _iInput, int _iMin, int _iMax);


template<typename T>
void Safe_Delete(T& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
}