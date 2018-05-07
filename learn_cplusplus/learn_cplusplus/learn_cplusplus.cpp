// learn_cplusplus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include "TestClass.h"
#include "MyStack.h"
#include <string>
#include <assert.h>
#include "TestOverloadOperator.h"
#include "AutoArray.h"
#include "Graph.h"
#include "MyString.h"
#include "FileExcute.h"
#include "FilePath.h"
#include "TemplateParatice.h"
#include "TestStringClass.h"
#include <list>
using namespace std;
const int N = 40;

template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
}

inline void sum(int& p, vector<int>& d)
{
	p = 0;
	for (auto iter = d.begin(); iter < d.end(); iter++)
		p += *iter;
}

void test_mystack()
{
	try
	{
		MyStack<int> intStack;
		MyStack<string> stringStack;

		intStack.push(7);
		cout << intStack.top() << endl;

		//操作string 类型的栈
		stringStack.push("hello");

		cout << stringStack.top() << endl;

		stringStack.pop();
		stringStack.pop();
	}
	catch (exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
	}
}

void testFuncConst()
{
	const TestClass A;
	A.testFunc();

	TestClass B;
	B.testFunc();
}

void testOperatorReload();

void testAutoArray();

int _tmain(int argc, _TCHAR* argv[])
{
	//test_stringClass();

	return 0;
}

void testOperatorReload()
{
	TestClass a;
	TestClass b;
	TestClass c = a + b;
	cout << "c.getID():" << c.getID() << endl;
	cout << "a.getID():" << a.getID() << endl;
	cout << "b.getID():" << b.getID() << endl;
	assert(c.getID() == a.getID() + b.getID());

	TestClass d;
	d.setID(8);
	assert(d % 3 == 2);
	assert(10 % d == 2);

	TestOverloadOperator op1;
	op1.setData(5);
	TestOverloadOperator op2 = op1++;
	TestOverloadOperator op3 = ++op1;

	assert(op1.getData() == 7);
	assert(op2.getData() == 5);
	assert(op3.getData() == 7);
}

void testAutoArray()
{
	AutoArray a;
	for (int i = 0; i < 5; i++)
	{
		a.push_back(i);
	}

	AutoArray b = a;
	assert(b[0] == 0);
	assert(b.length() == 5);
	AutoArray c;
	c = b;
	c[1] = 100;
	assert(c[1] = 100);
	cout << c << endl;
}
