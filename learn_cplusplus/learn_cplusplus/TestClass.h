#pragma once

class TestClass 
{
public:
	TestClass();
	TestClass(int i);
	TestClass(const TestClass& a);
	~TestClass();
	void printHello();
	void testFunc() const;

	//TestClass operator+(const TestClass& rhs);

	int getID() const;
	void setID(int id);
private:
	int id;
	static int gen;
};

TestClass operator+(const TestClass& lhs, const TestClass& rhs);

int operator%(int i, const TestClass& rhs);
int operator%(const TestClass& rhs , int i);