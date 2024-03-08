typedef struct _tabArr {
	int*	pInt;
	int		iCounter;
	int		iMaxCounter;
}tArr;

void InitArr(tArr* _pArr);
void PushBack(tArr* _pArr, int _IDate);
void Realocation(tArr* _pArr);
void ReleaseArr(tArr* _pArr);
void SortArr(tArr* _pArr, void (*SortFunc)(int*, int));