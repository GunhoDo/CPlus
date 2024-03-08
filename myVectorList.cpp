#include <iostream>
#include <vector>
#include <list>
#include "CList.h"

using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::list;


int main()
{
	/*CArr<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);
	CArr<int>::iterator myiter = myvector.begin();

	for (; myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}
	myiter = myvector.begin();
	int iData = *(++myiter);
	int iData1 = *(myiter++);
	return 0;

	CArr<int> myvector;

	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);
	myvector.push_back(40);


	CArr<int>::iterator myiter = myvector.begin();
	myiter = myvector.erase(++myiter);
	int i = *myiter; */

	CList<int> mylist;
	mylist.push_back(100);
	mylist.push_back(300);
	mylist.push_back(400);
	CList<int>::iterator listiter = mylist.begin();
	int l = *listiter;
	++listiter;
	mylist.insert(listiter, 200);
	mylist.erase(listiter);

	for (listiter = mylist.begin(); listiter != mylist.end(); ++listiter)
	{
		cout << *listiter << endl;
	}
	*listiter;//???

	return 0;
}