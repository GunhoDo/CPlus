#include "LinkedList.h"
#include <iostream>

int main()
{
	tLinkedList list = {};
	
	InitList(&list);
	/*
	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);
	*/
	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);

	ReleaseList(&list);
	return 0;
}