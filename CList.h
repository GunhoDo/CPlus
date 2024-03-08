#pragma once
#include <assert.h>

template<typename T>
struct tListNode
{
	T				data;
	tListNode*		pPrev; //내부에 있어서 <T>안써도 된다
	tListNode*		pNext; 
	
	tListNode()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{
	}
};

template<typename T>
class CList
{
private:
	tListNode<T>*	m_pHead;
	tListNode<T>*	m_pTail;
	int				m_iCount;
	
public:
	void push_back(const T& _data);
	void push_front(const T& _data);

	CList();
	~CList();

	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);
	
	class iterator
	{
	private:
		CList<T>*			m_pList;
		tListNode<T>*		m_pNode;
		bool				m_bValid;

	public:
		T& operator*()
		{
			return m_pNode->data;
		}
		bool operator == (const iterator& _other)
		{
			if (m_pList == _other.m_pList && m_pNode == _other.m_pNode)
			{
				return true;
			}
			return false;
		}
		bool operator != (const iterator& _other)
		{
			return !(*this == _other);
		}
		iterator& operator ++()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}
			m_pNode = m_pNode->pNext;
			return *this;
		}
		iterator& operator ++(int)
		{
			iterator copyiter(*this);
			++(*this);
			return copyiter;
		}
		iterator& operator --()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}
			m_pNode = m_pNode->pPrev;
			return *this;
		}
		iterator& operator --(int)
		{
			iterator copyiter(*this);
			--(*this);
			return copyiter;
		}
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{}
		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{
		}
		friend class CList;
	};
	
};

template<typename T>
void CList<T>::push_back(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
		m_pTail = pNewNode;
	}
	++m_iCount;
}

template<typename T>
void CList<T>::push_front(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		m_pHead->pPrev = pNewNode;
		m_pHead = pNewNode;
	}
	++m_iCount;
}

template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{
}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;
	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete pDeleteNode;
		pDeleteNode = pNext;
	}
}

template<typename T>
typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead);
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	if (this != _iter.m_pList || end() == _iter || !(_iter.m_bValid))
	{
		assert(nullptr);
	}
	if (_iter.m_pNode == _iter.m_pList->m_pHead)
	{
		_iter.m_pList->m_pHead = _iter.m_pNode->pNext;
	}
	if (_iter.m_pNode == _iter.m_pList->m_pTail)
	{
		_iter.m_pList->m_pTail = _iter.m_pNode->pPrev;
	}
	_iter.m_pNode->pPrev->pNext = _iter.m_pNode->pNext;
	_iter.m_pNode->pNext->pPrev = _iter.m_pNode->pPrev;
	_iter.m_bValid = false;
	--(_iter.m_pList->m_iCount);

	return iterator(this, _iter.m_pNode->pPrev);
}

template<typename T>
typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
		m_pHead = pNode;
	}
	else
	{
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this, pNode);
}

