//Date:2018/5/11
//Author:dylan_xi
//Desc: smart point use 
#include<iostream>
#include<memory> //must include it to use smart point
using namespace std;
struct A {
    int n;
    A(int v = 0):n(v){};
    ~A(){cout << n << "destructor" << endl;};
};
int main(int argc, char const *argv[])
{
    // by use shared_ptr'constructor to manage the dynamic allocated memory 
    shared_ptr<A> ptr(new A);
    //now , ptr 可以像使用指针A*一样使用shared_ptr.*ptr 
    //就是动态分配的那个对象,而不用担心内存释放的问题

    //多个shared_ptr 可以同时托管一个指针,系统会维护一个 refenrence count ,当无shared_ptr 托管该指针,delete指针
    //shared_ptr 不能托管指向动态分配的数组的指针,否则程序会出错
    shared_ptr<A> sp1(new A(2)); //sp1 托管 new A(2)
    shared_ptr<A> sp2(sp1);//复制构造sp2 也托管 new A(2)
    cout << "1)" << sp1->n << "," << sp2->n << endl;
    shared_ptr<A> sp3;
    A* p = sp1.get(); //p指向 sp1 托管的指针所指向的对象
    cout << "2)" << p->n << endl;

    sp3 = sp1; //sp3 也托管A(2)
    cout << "3)" << (*sp3).n << endl;
    sp1.reset(); //sp1 放弃托管A(2)
    if(!sp1) cout << "4)sp1 is null" << endl;
    A* q = new A(3);
    sp1.reset(q); //sp1 托管q
    cout << "5)" << sp1->n << endl;
    shared_ptr<A> sp4(sp1);
    shared_ptr<A> sp5;
    //sp5.reset(q) 不妥,会导致程序出错
    sp1.reset();
    cout << "before end main" << endl;
    sp4.reset();
    cout << "end main" << endl;
    return 0;
}