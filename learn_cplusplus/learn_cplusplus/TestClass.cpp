#include "stdafx.h"
#include "TestClass.h"
#include <iostream>
using namespace std;

int TestClass::gen = 0;

TestClass::TestClass()
{
	gen++;
	id = gen;
	cout << id << " default constructor called" << endl;
}

TestClass::TestClass(int i)
{
	gen++;
	id = gen;
	cout << id << " type convert constructor called" << endl;
}

TestClass::TestClass(const TestClass& a)
{
	gen++;
	id = a.id;
	//id = gen;
	cout << id << " copy constructor called" << endl;
}


TestClass::~TestClass()
{
	cout << id << " destructor called" << endl;
}

void TestClass::printHello()
{
	cout << "print hello" << endl;
}

void TestClass::testFunc() const
{
	cout << "testConstFunc" << endl;
}

/*TestClass TestClass::operator+(const TestClass& rhs)
{
	TestClass addResult;
	addResult.id = this->id + rhs.id;
	return addResult;
}*/

int TestClass::getID() const
{
	return id;
}

void TestClass::setID(int id)
{
	this->id = id;
}

TestClass operator+(const TestClass& lhs, const TestClass& rhs)
{
	TestClass addResult;
	addResult.setID(lhs.getID() + rhs.getID());
	return addResult;
}

int operator%(const TestClass& rhs, int i)
{
	return rhs.getID() % i;
}

int operator%(int i, const TestClass& rhs)
{
	return i % rhs.getID();
}
