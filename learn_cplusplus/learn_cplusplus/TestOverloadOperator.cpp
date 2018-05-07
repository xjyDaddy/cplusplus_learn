#include "stdafx.h"
#include "TestOverloadOperator.h"


TestOverloadOperator::TestOverloadOperator(int data)
{
	this->data = data;
}

TestOverloadOperator::TestOverloadOperator()
{

}

TestOverloadOperator::~TestOverloadOperator()
{

}

TestOverloadOperator TestOverloadOperator::operator++()
{
	data++;
	TestOverloadOperator result;
	result.data = data;
	return result;
}

TestOverloadOperator TestOverloadOperator::operator++(int)
{
	TestOverloadOperator result;
	result.data = data;
	data++;
	return result;
}

int TestOverloadOperator::getData() const
{
	return data;
}

void TestOverloadOperator::setData(int data)
{
	this->data = data;
}
