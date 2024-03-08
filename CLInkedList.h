#pragma once
template<typename T>
class CNode 
{
public:
	T			iData;
	CNode<T>*	pNextNode;
	CNode<T>*	pPrevNode;
};

template<typename T>
class CLinkedList
{
private:
	CNode<T>*	pHeadNode;
	CNode<T>*	ptailNode;
	int			iCount;
public:
	CLinkedList();
	~CLinkedList();
	void PushBack(const T &_iData);
	void PushFront(const T &_iData);
};

template<typename T>
CLinkedList<T>::CLinkedList()
	: pHeadNode(nullptr)
	, ptailNode(nullptr)
	, iCount(0)
{
}

template<typename T>
CLinkedList<T>::~CLinkedList()
{
	CNode<T>* pCurrentNode = pHeadNode;
	while (pCurrentNode)
	{
		CNode<T>* temp = pCurrentNode->pNextNode;
		delete pCurrentNode;
		pCurrentNode = temp;
	}
}

template<typename T>
void CLinkedList<T>::PushBack(const T &_iData)
{
	CNode<T>* pNode = new CNode<T>[1];
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;
	pNode->pPrevNode = nullptr;
	if (0 == iCount)
	{
		pHeadNode = pNode;
	}
	else
	{
		CNode<T>* CurrentNode = pHeadNode;
		while (CurrentNode->pNextNode)
		{
			CurrentNode = CurrentNode->pNextNode;
		}
		pNode->pPrevNode = CurrentNode;
		CurrentNode->pNextNode = pNode;
		ptailNode = pNode;
	}
	++iCount;
}

template<typename T>
void CLinkedList<T>::PushFront(const T& _iData)
{
	CNode<T>* pNode = new CNode<T>[1];
	pNode->iData = _iData;
	pNode->pNextNode = pHeadNode;
	if (0 == iCount)
	{
		ptailNode = pNode;
	}
	else
	{
		pHeadNode->pPrevNode = pNode;
	}
	pHeadNode = pNode;
	iCount++;
}
