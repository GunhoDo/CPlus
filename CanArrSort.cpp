#include <iostream>
#include "Arr.h"
#include <time.h>
void BubbleSort(int* _pData, int _iCount)
{
	for (int i = 0; i < _iCount - 1; ++i)
	{
		for (int j = _iCount - 1; j > i; j--)
		{
			if (_pData[j] < _pData[j - 1])
			{
				int temp = _pData[j];
				_pData[j] = _pData[j - 1];
				_pData[j - 1] = temp;
			}
		}
	}
}
// -버블, 삽입, 선택, 합병(머지), 쾌속(퀵), 힙(완전이진트리)

int main() 
{
	tArr s;

	srand(time(NULL));

	InitArr(&s);

	for (int i = 0; i < 10; ++i)
	{
		int RAND = rand() % 100 + 1;
		PushBack(&s, RAND);
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}


	SortArr(&s, &BubbleSort);
	
	printf("---------정렬----------");

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	ReleaseArr(&s);

	return 0;
}