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
	//��Ҫ����()����ʵ��,��������
	cout << s1(0, 4) << endl;
}
