#include <iostream>
namespace MYSPACE
{
	int g_int;
}
using std::cout;
using std::cin;
using std::endl;
using std::wcout;

void MyEndL()
{
	wprintf(L"\n");
}
class CMyOStream
{
public:
	CMyOStream& operator << (int data)
	{
		printf("%d", data);
		return *this;
	}
	CMyOStream& operator << (const wchar_t* data)
	{
		wprintf(L"%s", data);
		return *this;
	}
	CMyOStream& operator >> (int& data)
	{
		scanf_s("%d", &data);
		return *this;
	}
	CMyOStream& operator << (void(*func)(void))
	{
		func();
		return *this;
	}
};

CMyOStream mycout;

int main()
{
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");
	mycout << 10;
	mycout << L"ÇÑ±Û";
	int a = 0;
	mycout >> a << MyEndL;
	return 0;
}