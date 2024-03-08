#include <iostream>
#include <map>
#include <set>
#include <string>
#include "CBST.h"


// ���� ���� Ʈ�� -> �迭(�� �ڷᱸ��)
// [���� Ž��] Ʈ�� -> 1. �����Ͱ� ����, 2. ��� ����

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;
using std::wstring;
// ����Ž��Ʈ��
// 1. ���� Ž���� ����� �� �ְ� ��ȵ� Ʈ��
// 2. ������ �Է½� O(logN) ȿ��
// 3. Ž�� ȿ���� O(logN)
// 4. Ʈ���� ����� �뷱���� �������� ������ ����ε� Ž�� ȿ���� ������ �ʴ´�
//     - �ڰ���������� �ʿ� (AVL, Red/Black)

#define MAN 1
#define WOMAN 2

struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;
	tStdInfo()
		:szName{}
		, age(0)
		, gender(0)
	{

	}
	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

struct pair
{
	const wchar_t*	first;
	tStdInfo		second;
};

enum class My_TYPE
{
	TYPE_1,
	TYPE_2,
	TYPE_3,
	TYPE_4 = 100,
	TYPE_5,
};

enum class OTHER_TYPE
{
	TYPE_1,
};

class MyClass
{
private:
	int a;
public:
	bool operator < (const MyClass& _other) const
	{
		if (a < _other.a)
			return true;
		else
			return false;
	}
};

int main()
{
	set<int> setInt;

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	mapData.insert(make_pair(L"ȫ�浿", info));
	mapData.insert(make_pair(L"������", info2));

	wchar_t szFind[20] = L"������"; // ���ڰ� �����ؼ��� �ƴ϶� �ּҰ��� ���ұ� ������ ã�� ���̴�
	map<const wchar_t*, tStdInfo>::iterator mapiter;
	
	mapiter = mapData.find(szFind);
	

	_wsetlocale(LC_ALL, L"korean");

	if (mapiter == mapData.end())
	{
		wcout << L"�����͸� ã�� �� ����." << endl;
	}
	else
	{
		wcout << L"�̸� : " << mapiter->second.szName << endl;
		wcout << L"���� : " << mapiter->second.age << endl;
		wcout << L"���� : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else
		{
			wcout << L"�� �� ����" << endl;
		}
	}

	map<MyClass, tStdInfo> mapStdInfo; // key ���� �����͸� ������ �б�����޸�(rom)�� ����� �ּҰ����� ã�� ���̱⿡ �ݵ�� Class�� ���
	MyClass a;
	mapStdInfo.insert(make_pair(a, info));

	wstring str;  // ��ǻ� ���ڿ� �����迭 vector<wchar_t>
	str = L"abcdef";
	wstring str2 ;
	if (str == str2)
	{

	}

	CBST<int, int> bstint;
	tPair<int, int> pair;
	
	
	bstint.insert(make_bstpair(100, 0));  //
	bstint.insert(make_bstpair(150, 0));  //		 100
	bstint.insert(make_bstpair(50, 0));   //      50	  150
	bstint.insert(make_bstpair(25, 0));   //	25	75	125	175
	bstint.insert(make_bstpair(75, 0));
	bstint.insert(make_bstpair(125, 0));
	bstint.insert(make_bstpair(175, 0));


	CBST<int, int>::iterator itbst = bstint.begin();
	itbst=bstint.find(100); 
	itbst = bstint.erase(itbst);

	itbst = bstint.find(150);
	itbst = bstint.erase(itbst);

	(*itbst).first;
	itbst->first;



	for (itbst = bstint.begin(); itbst != bstint.end(); ++itbst)
	{
		wcout << itbst->first << itbst->second << endl;
	}



	int c = (int)My_TYPE::TYPE_1;

	map<int, int> mapint;
	mapint.insert(make_pair(100, 100));
	map<int,int>::iterator iter = mapint.find(100);
	if (iter == mapint.end())
	{

	}


	return 0;
}
