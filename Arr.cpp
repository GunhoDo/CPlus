#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int*) * 2);
	_pArr->iCounter = 0;
	_pArr->iMaxCounter = 2;
}

void Realocation(tArr* _pArr)
{
	int* pNew = (int*)malloc(sizeof(int*) * 2 * _pArr->iMaxCounter);
	for (int i = 0; i < _pArr->iCounter; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}
	free(_pArr->pInt);
	_pArr->iMaxCounter *= 2;
	_pArr->pInt = pNew;
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCounter = 0;
	_pArr->iMaxCounter = 0;
}

void SortArr(tArr* _pArr, void (*SortFunc)(int*, int))
{
	SortFunc(_pArr->pInt, _pArr->iCounter);
}


void PushBack(tArr* _pArr, int _IDate)
{
	if (_pArr->iCounter >= _pArr->iMaxCounter)
	{
		Realocation(_pArr);
	}
	_pArr->pInt[_pArr->iCounter++] = _IDate;
}
