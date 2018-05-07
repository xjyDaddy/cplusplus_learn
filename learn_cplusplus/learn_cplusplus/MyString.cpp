#include "stdafx.h"
#include "MyString.h"
#include <string>


MyString::~MyString()
{
}

string MyString::operator()(int beg, int length) const
{
	string s = substr(beg, length);
	return s;
}

MyString::MyString(const char* str) :string(str)
{
	
}

void test_myString()
{
	string s("abcdefgh");
	MyString s1("abcdefgh");
	//需要重载()才能实现,函数对象
	cout << s1(0, 4) << endl;
}
