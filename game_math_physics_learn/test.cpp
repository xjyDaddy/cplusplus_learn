#include"Point3D.h"
#include "Slope.h"
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float P1[2] = {1 , 2};
    float P2[2] = {3 , 4};

    cout << slopeBetweenPoints(&P1 , &P2) << endl;

    return 0;
}


