#include <iostream>
#include "CList.h"

class CMy
{
private:
	int i;
	float j;

public:
	void SetInt(int a)
	{
		this->i = a;
	}
	const CMy& operator =(const CMy& _Other)
	{
		if (this != &_Other) {
			i = _Other.i;
			j = _Other.j;
		}
		return *this;
	}
	CMy()
		:i(100) ,j(0.f)
	{
	}
	~CMy()
	{
	}
};

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{

	CList<int> clink;
	clink.push_front(100);
	clink.push_front(200);
	clink.push_front(300);

	return 0;
}