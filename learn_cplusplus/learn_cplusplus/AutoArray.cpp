#include "stdafx.h"
#include "AutoArray.h"


AutoArray::AutoArray()
{
	pElems = nullptr;
	iSize = 0;
}

AutoArray::AutoArray(const AutoArray& array)
{
	clear();
	if (array.pElems)
	{
		pElems = new int[array.iSize];
		memcpy(pElems, array.pElems, sizeof(int)*array.iSize);
		iSize = array.iSize;
	}
}


AutoArray::~AutoArray()
{
	if (pElems)
	{
		delete[] pElems;
	}
}

AutoArray& AutoArray::operator=(const AutoArray& rhs)
{
	if (&rhs == this)
	{
		return *this;
	}

	clear();

	if (rhs.pElems)
	{
		pElems = new int[rhs.iSize];
		memcpy(pElems, rhs.pElems, sizeof(int)*rhs.iSize);
		iSize = rhs.iSize;
	}
	return *this;
}

void AutoArray::push_back(int elem)
{
	int * pTempElems = new int[iSize + 1];
	if (pElems != nullptr) 
		memcpy(pTempElems, pElems, sizeof(int)*iSize);
	pTempElems[iSize] = elem;
	int iSizeTemp = iSize;
	clear();
	pElems = pTempElems;
	iSize = iSizeTemp + 1;
}

void AutoArray::clear()
{
	if (pElems)
	{
		delete []pElems;
		pElems = nullptr;
		iSize = 0;
	}
}



std::ostream& operator<<(std::ostream& os, const AutoArray& array)
{
	for (int i = 0; i < array.length(); i++)
	{
		os << array[i] << " ,";
	}
	return os;
}
