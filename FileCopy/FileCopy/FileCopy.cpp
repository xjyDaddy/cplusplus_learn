// FileCopy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 3)
	{
		cout << "File name missing" << endl;
		return 0;
	}

	ifstream inFile(argv[1], ios::in | ios::binary);
	if (!inFile)
	{
		cout << "open file:" << argv[1] << " error" << endl;
		return 0;
	}

	ofstream outFile(argv[2], ios::out | ios::binary);
	if (!outFile)
	{
		cout << "open file:" << argv[2] << "error" << endl;
		inFile.close();
		return 0;
	}

	char c;
	while (inFile.get(c))
	{
		outFile.put(c);
	}

	outFile.close();
	inFile.close();

	return 0;
}

