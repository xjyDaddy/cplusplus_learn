#pragma once
#include <iostream>

class AutoArray
{
	friend std::ostream& operator<<(std::ostream& os, const AutoArray& array);
public:
	AutoArray();
	AutoArray(const AutoArray& array);

	~AutoArray();

	AutoArray& operator=(const AutoArray& rhs);
	int& operator[](int i) const{ return pElems[i]; };

	void push_back(int elem);
	int length() const{ return iSize; } ;

private:
	int* pElems;
	int iSize;

	void clear();
};

std::ostream& operator<<(std::ostream& os, const AutoArray& array);
