#include <iostream>
#include <map>
#include <set>
#include <string>
#include "CBST.h"


// 완전 이진 트리 -> 배열(힙 자료구조)
// [이진 탐색] 트리 -> 1. 데이터가 정렬, 2. 계속 절반

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;
using std::wstring;
// 이진탐색트리
// 1. 이진 탐색을 사용할 수 있게 고안된 트리
// 2. 데이터 입력시 O(logN) 효율
// 3. 탐색 효율은 O(logN)
// 4. 트리의 모양이 밸런스가 유지되지 않으면 제대로된 탐색 효율이 나오지 않는다
//     - 자가균형기능이 필요 (AVL, Red/Black)

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

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info));
	mapData.insert(make_pair(L"이지혜", info2));

	wchar_t szFind[20] = L"이지혜"; // 문자가 동일해서가 아니라 주소값이 같았기 때문에 찾은 것이다
	map<const wchar_t*, tStdInfo>::iterator mapiter;
	
	mapiter = mapData.find(szFind);
	

	_wsetlocale(LC_ALL, L"korean");

	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 찾을 수 없다." << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		wcout << L"성별 : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"남자" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		else
		{
			wcout << L"알 수 없음" << endl;
		}
	}

	map<MyClass, tStdInfo> mapStdInfo; // key 값에 포인터를 넣으면 읽기전용메모리(rom)에 저장된 주소값으로 찾는 것이기에 반드시 Class를 사용
	MyClass a;
	mapStdInfo.insert(make_pair(a, info));

	wstring str;  // 사실상 문자용 가변배열 vector<wchar_t>
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
