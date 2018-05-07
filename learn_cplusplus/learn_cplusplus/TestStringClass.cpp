#include "stdafx.h"
#include "TestStringClass.h"
#include <string>
#include <iostream>
using namespace std;
void test_stringClass()
{
	string s("hello world");
	cout << s.find("ll") << endl;
	cout << s.find("abc") << endl;
	cout << s.rfind("ll") << endl;
	cout << s.find_first_of("abcde") << endl;
	cout << s.find_first_not_of("hewel") << endl;
	
}
