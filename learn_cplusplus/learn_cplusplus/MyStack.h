#pragma once

#include <vector>
template <class T>
class MyStack
{
public:
	MyStack();
	~MyStack();

	void push(T const& elem);
	void pop();
	T top() const;
	bool empty() const;
private:
	std::vector<T> elems;
};

template <class T>
MyStack<T>::~MyStack()
{

}

template <class T>
MyStack<T>::MyStack()
{

}

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



