//Date:2018/5/11
//Author:dylan_xi
//Desc: c++11 feature
#include<iostream>
using namespace std;
struct T {T(int a){n = a;}; int n;};
int main(int argc, char const *argv[])
{
    int i;
    double t;
    struct A {double x;};
    const A* a = new A();
    //获取变量类型 decltype
    decltype(i) x1 = 2;
    decltype(t) x2 = 2.0;
    decltype(a) x3 = new A();

    //error,不能这么调用, T(1)是右值, 不能引用右值
    //一般来说能取地址的就是左值,不能取地址的就是右值
    // T& t1 = T(1);
    //ok,r 是右值引用.
    T &&r = T(1);
    //右值引用的目的是为了提高程序的运行效率,减少需要进行深拷贝的对象进行深拷贝的次数.
    cout << r.n << endl;
    /* code */
    return 0;
}
