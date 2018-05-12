//Date:2018/5/12
//Author:dylan_xi
//Desc: lambda use in c++

/*
    形式:
    [外部变量访问方式说明符](参数表) ->返回值类型
    {
        语句组
    }

    ">返回值类型" 也可以没有,编译器自动判断返回值类型

    [=] 以传值的形式使用所有外部变量
    []  不使用任何外部变量
    [&] 以引用形式使用所有外部变量
    [x , &y] x以传值形式使用,y以引用方式使用
    [= ,&x ,&y] x ,y以引用使用,其他以传值使用
    [& ,x ,y]   x ,y以传值使用,其他以传引用使用
*/

#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;


int main(int argc, char const *argv[])
{
    int x = 100 , y =200 ,z =300;
    cout << [](double a , double b){return a + b;}(1.2,2.5) <<endl;

    auto ff = [=,&y,&z](int n){
        cout << x << endl;
        y++ ; z++;
        return n*n;
    };
    cout << ff(15) << endl;
    cout << y << ", " << z << endl;

    //lambda for sort 
    int a[4] = {4,2,11,33};
    sort(a , a+4 ,[](int x ,int y){
            return x%10 < y %10;
        });
    for_each(a , a + 4 , [](int x){
        cout << x << endl;
    });

    //lambda for fibnassi
    function<int(int)> fib = [&fib](int n){
        return n <= 2? 1: fib(n-1) + fib(n-2);
    };
    cout << fib(5) << endl;

    return 0;
}
