#include "LinkedList.h"
#include <iostream>
void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		tNode* CurrentNode = _pList->pHeadNode;
		while (CurrentNode->pNextNode)
		{
			CurrentNode = CurrentNode->pNextNode;
		}
		CurrentNode->pNextNode = pNode;
	}
	++_pList->iCount;
}

void ReleaseList(tLinkedList* _pList)
{
	tNode* pCurrentNode = _pList->pHeadNode;
	while (pCurrentNode) 
	{
		tNode* temp = pCurrentNode->pNextNode;
		free(pCurrentNode);
		pCurrentNode = temp;
	}
}

void PushFront(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;
	_pList->pHeadNode = pNode;
	_pList->iCount++;
}
