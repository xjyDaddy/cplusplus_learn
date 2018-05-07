#include "stdafx.h"
#include "FileExcute.h"
#include <fstream>
#include <iostream>
using namespace std;
const char* fileName = "file.dat";
void test_fstream()
{
	//打开文件写入
	ofstream outFile(fileName , ios::out|ios::binary);
	if (!outFile)
	{
		cerr << "open file failed!" << endl;
		return;
	}
	cout << "write to file" << endl;
	cout << "input data" << endl;
	int data;
	while (cin >>data)
	{
		cout << data << endl;
		outFile << data << endl;
	}
	outFile.close();
	
	//打开文件读入
	ifstream inFile(fileName, ios::in | ios::binary);
	if (!inFile)
	{
		cerr << "open file failed" << endl;
	}
	while (inFile >> data)
	{
		cout << data << endl;
	}
	inFile.close();

	//打开文件读入,指针操作
	ifstream inFileForPointerOperator(fileName, ios::in | ios::binary);
	if (!inFileForPointerOperator)
	{
		cerr << "open file failed" << endl;
	}
	cout << "open file for pointer Operator" << endl;
	long pos = 1L;
	inFileForPointerOperator.seekg(pos);
	inFileForPointerOperator >> data;
	cout << data << endl;
}

void test_studentFile()
{
	Student student;
	//打开学生成绩文件用于写入
	/*ofstream outFile("students.dat", ios::out | ios::binary);
	if (!outFile)
	{
		cout << "open file failed" << endl;
		return;
	}
	while (cin >> student.szName >> student.nScore)
	{
		if (strcmp(student.szName , "exit") == 0)
		{
			break;
		}
		outFile.write((char*)&student, sizeof(student));
	}
	outFile.close();
	*/
	//打开学生成绩文件用于读出
	ifstream inFile("students.dat", ios::in | ios::binary);
	if (!inFile)                                                                                       
	{
		cout << "open file failed" << endl;
		return;
	}

	while (inFile.read((char*)&student , sizeof(student)))
	{
		streamsize nReadedBytes = inFile.gcount();
		cout << "readed bytes:" << nReadedBytes << endl;
		cout << "name:" << student.szName << ", score:" << student.nScore << endl;
	}
	inFile.close();

	//打开学生成绩文件用于读写
	fstream iofile("students.dat", ios::in | ios::out | ios::binary);
	if (!iofile)
	{
		cout << "open file failed" << endl;
		return;
	}
	iofile.seekp(2*sizeof(student), ios::beg);
	iofile.write("jacky", strlen("jacky") + 1);

	iofile.seekg(ios::beg);
	while (iofile.read((char*)&student , sizeof(student)))
	{
		cout << "name:" << student.szName << ", score:" << student.nScore << endl;
	}
	iofile.close();
}
