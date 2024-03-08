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
	// 객체지향 언어 특징
	// 1. 캡슐화(은닉성)
	// 2. 상속, 상속받은 아들 클래스가 부모 클래스의 private 변수에 접근할 수 없다 이를 가능하게 하려면 protected를 사용
	// 3. 다형성
	// 4. 추상화

	CParent parenct;

	CChild child;

	return 0;
}