#pragma once
#include <string>
#include <iostream>
using namespace std;
class MyString :public string
{
public:

	/*
		构造函数不能被子类继承(可以继承父类所有的的成员变量和成员方法,但不能继承父类的构造方法),因此
		在创建子类对象时,为了初始化从父类继承来的数据成员,系统需要调用其父类的构造方法

		没有显示的构造函数,编译器会给一个默认的的构造函数,仅在没有显示地声明构造函数的情况下创建

		构造规则如下:
			1.子类没有定义构造方法,则调用父类的无参数构造方法
			2.如果子类定义了构造,无论是无参数还是带参数,在创建子类的对象时，首先执行父类无参数的构造方法,然后执行自己的
			3.在创建子类对象,如果子类构造函数没有显示调用父类的构造函数，则会调用无参版本
			4.如果子类构造函数没有显示调用父类构造函数且父类,只定义了有参数版本构造函数，则会出错。
	*/
	MyString(const char* str);
	string operator()(int beg, int length) const;
	~MyString();
};


void test_myString();