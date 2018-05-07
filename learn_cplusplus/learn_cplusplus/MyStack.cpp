#include "stdafx.h"
#include "MyStack.h"
using namespace std;

template <class T>
bool MyStack<T>::empty() const
{
	return elems.empty();
}

template <class T>
T MyStack<T>::top() const
{
	if (elems.empty())
		throw out_of_range("Stack<>::pop(): empty stack");
	return elems.back();
}

template <class T>
void MyStack<T>::pop()
{
	if (elems.empty())
		throw out_of_range("Stack<>::pop(): empty stack");
	elems.pop_back();
}

template <class T>
void MyStack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

