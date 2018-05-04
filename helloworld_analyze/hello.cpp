//Date:2018/5/4
//Author:dylan_xi
//Desc: analyze g++ hello.cpp compile and run process
//learn more from blog: https://blog.csdn.net/qq_16949707/article/details/54410262
/*
    (1) Pre-Processing(.i): g++ -E hello.cpp -o hello.i
    (2) Compiling(.s): g++ -S hello.cpp hello.s
    (3) Assembling(.o): g++ -c hello.cpp -o hello.o
    (4) Linking(.lib,.exe): g++ hello.o -o hello.exe

    to be continus:
    add more details about static libray and dynamic library in the future...
*/

#include<iostream>
using namespace std;
int main()
{
    cout << "hello world" << endl;
    return 0;
}