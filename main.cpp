#include <iostream>

class CParent
{
private:
	int m_i;

public:
	CParent()
		:m_i(0)
	{}
	~CParent()
	{}
};


class CChild : public CParent
{
private:
	float	m_f;

public:
	CChild()
		: m_f(0.f)
	{}
	~CChild()
	{}
};



int main()
{
	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ(���м�)
	// 2. ���, ��ӹ��� �Ƶ� Ŭ������ �θ� Ŭ������ private ������ ������ �� ���� �̸� �����ϰ� �Ϸ��� protected�� ���
	// 3. ������
	// 4. �߻�ȭ

	CParent parenct;

	CChild child;

	return 0;
}