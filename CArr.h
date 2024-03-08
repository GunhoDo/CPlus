#pragma once
#include <assert.h>

template<typename T>
class CArr
{
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;

public:
	void resize(int _iResizeCount);
	void push_back(const T &_Data);

	T* data() { return m_pData; };
	int size() { return m_iCount; };
	int capacity() { return m_iMaxCount; };

	T& operator[] (int idx);
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);

	void clear() { m_iCount = 0; };
	CArr();
	~CArr();

	class iterator //이너 클래스를 포함하고 있는 멤버의 private 변수를 가져 올 수 있따
	{
	private:
		CArr*	m_pArr;
		T*		m_pData;
		int		m_iIdx;
		bool	m_bValid;

	public:
		T& operator * ()
		{
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx || !m_bValid)
			{
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		iterator& operator ++()
		{
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
				assert(nullptr);
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}
			return *this;
		}

		iterator operator ++(int)
		{
			iterator copy_iter = *this; // 대입연산자 X 복사 생성자 O
			++(*this);
			return copy_iter;
		}

		iterator& operator --()
		{
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
				assert(nullptr);
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				--m_iIdx;
			}
			return *this;
		}

		iterator operator --(int)
		{
			iterator copy_iter = *this; 
			--(*this);
			return copy_iter;
		}


		bool operator ==(const iterator& _other)
		{
			if (m_pData == _other.m_pData && m_iIdx == _other.m_iIdx)
			{
				return true;
			}
			return false;
		}
		bool operator !=(const iterator& _other)
		{
			return !(*this == _other);
		}

		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{
		}
		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(false)
		{
			if (nullptr != _pArr && 0 <= _iIdx)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{
		}
		friend class CArr;
	};
};

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}
	T* pNew = new T[_iResizeCount];
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}
	delete[] m_pData;
	m_iMaxCount = _iResizeCount;
	m_pData = pNew;
}
template<typename T>
void CArr<T>::push_back(const T &_Data)
{
	if (m_iCount >= m_iMaxCount)
	{
		resize(m_iMaxCount * 2);
	}
	m_pData[m_iCount++] = _Data;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin() // typename은 이너클래스 특정 타입이란 걸 알려주기 위함(CArr 안의 iterator)
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1);// 변수명 생략 만든 순간 제외하고 접근할 방법없음
	else
		return iterator(this, m_pData, 0);
} 

template<typename T>
typename CArr<T>::iterator CArr<T>::end() // typename은 이너클래스 특정 타입이란 걸 알려주기 위함(CArr 안의 iterator)
{
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	//또다른 객체의 이터레이터가 가리킨 경우
	//iterator가 end iterator인 경우
	if (this != _iter.m_pArr || end() == _iter || m_iCount <= _iter.m_iIdx)
	{ 
		assert(nullptr);
	}

	// iterator 가 가리키는 데이터를 배열 내에서 제거한다
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}

	_iter.m_bValid = false;
	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx);
}

