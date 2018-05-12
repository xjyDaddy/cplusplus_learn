//Date:2018/5/12
//Author:dylan_xi
//Desc: lambda use in static_cast , dynamic_cast , const_cast , interpret_cast.
#include<iostream>
using namespace std;
class A
{
    public:
        operator int() {return 1;}
        operator char*() {return nullptr;}
};

class B
{
public:
    int i;
    int j;
    B(int n):i(n){}
};

class Base{virtual void f(){};};
class Derived:public Base{virtual void f(){};};
int main(int argc, char const *argv[])
{
    /*
        (1)static_cast 
            用来比较"自然"和低风险的传换,比如整形和实数型 , 字符型之间互相转换
        不能用于整形和指针的互相转换,也不能用于不同类型的引用转换
    */      
    A a;
    int n;
    char p1[] = "nnnn";
    char* p = p1;
    n = static_cast<int>(3.14);
    cout << n << endl;
    //要求 a对象所对应的类,overload operator int
    n = static_cast<int>(a);    
    cout << n << endl;

    //调用 a.operator char*,p 的值变为 nullptr
    p = static_cast<char*>(a);
    //error , static_cast can't change a pointer to int  
    //n = static_cast<int>(p);
    //error ,static_cast can't change int type to a pointer
    //p = static_cast<char*>(n);

    /*
        (2)reinterpret_cast:
        用来进行各种不同类型指针的转换,不同类型引用之间的转换,以及指针和能容纳下指针的整数类型转换.转换的
        时候,执行的是逐个比特拷贝的操作
    */
    n = reinterpret_cast<int>(p);
    cout << n << endl;
    cout << reinterpret_cast<long>(p) << endl;

    B b(100);
    int &r = reinterpret_cast<int&>(b);
    cout << r << endl;
    r = 200;

    B* pb = reinterpret_cast<B*>(&n);
    pb->i = 400;
    pb->j = 500;  //此条语句不安全,很可能导致崩溃
    cout << n << endl; //输出400
    
    long long la = 0x123456789abcdLL;
    pb =  reinterpret_cast<B*>(la);
    cout << &pb <<endl;

    /*
        (3) const_cast
        用来进行去除const 属性的转换.将const 引用转换成同类型的非const 引用,
        将const 指针转换为同类型的非const 指针时用它.
    */
    const string s = "Inception";
    string & ps1 = const_cast<string&>(s); 
    string * ps2 = const_cast<string*>(&s); //&s的类型是const string

    /*
        (4) dynamic_cast
        dynamic_cast 专门用于将多态基类的指针或引用,强制转换为派生类的指针
        或引用,而且能够检查转换的安全性.对于不安全的指针转换,转换结果返回NULL指针
        dynamic_cast 不能用于将非多态基类的指针或引用,强制转换为派生类的指针或引用
        dynamic 机制是与对象的虚函数表指针相关联的.
    */
    
    Base* base = new Derived();
    Derived* derived;

    derived = dynamic_cast<Derived*>(base);   
    if(derived)
    {
        cout << "dynamic_cast success" << endl;
    }
    return 0;
}

