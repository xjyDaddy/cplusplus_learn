//Date:2018/5/12
//Author:dylan_xi
//Desc: regular expression use in c++

#include<iostream>
#include<regex>
using namespace std;


int main(int argc, char const *argv[])
{
    regex reg("b.?p.*k");
    cout << regex_match("bopggk", reg) <<endl;;
    cout << regex_match("boopggk", reg) << endl;
    return 0;
}
