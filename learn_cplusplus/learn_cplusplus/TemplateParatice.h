#pragma once

template <class T>
void MySwap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template<class T1 , class T2>
T2 print(T1 arg1, T2 arg2)
{
	std::cout << arg1 << " " << arg2 << endl;
	return arg2;
}

// ģ��ļ̳�
/*
	(1) ��ģ�����ģ������
*/

template <class T1 , class T2>
class A{
	T1 v1; T2 v2;
};

template <class T1 , class T2>
class B :public A<T2, T1>{
	T1 v3; T2 v4;
};

template <class T>
class C :public B<T, T>{
	T v5;
};

/*
	(2) ��ģ���ģ��������
template<class T1 , class T2>
class A2{ T1 v1; T2 v2 };

template<class T>
class B2 :public A2<int, double>{T v};
*/
/*
	(3) ��ģ�����ͨ������


class A3{ int v1; };
template<class T>
class B3 :public A{T v};
*/
/*
(4) ��ͨ���ģ��������
template<class T>
class A4{ T v1; };
class B4 :public A4<int>{ int v; };
*/
