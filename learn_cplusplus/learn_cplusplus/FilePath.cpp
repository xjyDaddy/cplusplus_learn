#include "stdafx.h"
#include "FilePath.h"
#include <direct.h>
#include <iostream>
#include <stdio.h>
using namespace std;
void test_FilePath()
{
	//��ȡ��ǰ����Ŀ¼
	char buffer[_MAX_PATH];
	_getcwd(buffer, _MAX_PATH);
	cout << buffer << endl;
}
