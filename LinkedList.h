#pragma once

typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode;
}tNode;

typedef struct _tagList
{
	tNode* pHeadNode;
	int iCount;

}tLinkedList;

void InitList(tLinkedList* _pList);

void PushBack(tLinkedList* _pList, int _iData);

void ReleaseList(tLinkedList* _pList);

void PushFront(tLinkedList* _pList, int _iData);