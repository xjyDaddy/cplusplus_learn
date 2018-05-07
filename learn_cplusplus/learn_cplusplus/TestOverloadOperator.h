#pragma once
class TestOverloadOperator
{
public:
	TestOverloadOperator();
	TestOverloadOperator(int data);
	~TestOverloadOperator();

	TestOverloadOperator operator++();
	TestOverloadOperator operator++(int);

	int getData() const;
	void setData(int data);
private:
	int data;
};

