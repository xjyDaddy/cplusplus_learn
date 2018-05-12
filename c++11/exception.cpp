//Date:2018/5/12
//Author:dylan_xi
//Desc: learn how to use exception in cplusplus.

/*
    程序运行中难免遇到问题:
    (1) 数组元素下标超界,访问NULL指针
    (2) 除数为0
    (3) 动态内存分配 new 需要的存储空间太大.
    (4) ...

    引起这些异常情况的原因:
        代码质量不高,存在BUG
        输入数据不符合要求
        程序的算法设计考虑不周到
    我们总是希望在发生异常的时候,不只是简单地终止程序运行
    能够反馈异常情况的信息:哪一段代码发生的,什么异常
    能够对程序运行中已发生的事情做些处理:取消对输入文件的改动,释放已申请的系统资源.

    通常的做法是:在预计会发生异常的地方,加入很多判断代码,但是这种做法并不总是适用
    (1) 这样非常繁琐
    (2) 以下情况:
        ...//对文件A进行了相关的操作
        func(arg , ......); //可能发生异常
        调用该函数的调用者该如何知道fun(arg, ....)是否发生异常呢?
        调用者希望: 
            没有发生异常,程序继续执行
            发生异常,应该在结束程序运行前还原对文件A操作
        编写者是不会知道其他人如何使用这个函数.fun(arg , .....)会出现在表达式中,通过返回值的方式
        通过返回值告诉是否发生异常
            (1) 不符合编程习惯
            (2) 要是有多个异常呢? 通过返回值判断会很麻烦
    需要一种手段把异常与函数的接口分开,并且能够区分不同异常
    在函数体外捕获异常,并提供更多异常信息
*/
/* use try , catch 处理异常*/
#include<iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    double m , n;
    cin >> m >> n;
    
    try
    {
        if(n == 0)
            throw -1; //抛出int 类型异常
        else if (m == 0)
            throw 1.0;
        else
            cout << m / n << endl;
        cout << "after adviding" << endl;
    }
    catch(double t)
    {
        cout << "catch(double)" << endl;
    }
    catch(int e)
    {
        cout << "catch(int)" << endl;
    }
    catch(...)
    {
        cout << "catch(...)" << endl;
    }
    return 0;
}
