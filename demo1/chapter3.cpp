//
// Created by zhaozhenguo on 2022/3/15.
//

#include "chapter3.h"

using namespace std;

#include <iostream>


void testA() {
    int a = 99;
    const int &r = a;
    cout << "a value:" << a << endl;
    cout << "r value:" << r << endl;
}

void swapA(int &r1, int &r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

void swapB(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int &plusA(int &r) {
    r += 10;
    return r;
}

void testB() {
    int a = 10;
    int &r = a;
    int b = plusA(r);
    cout << "result:" << b << endl;
}

//int main() {
////    testA();
//    testB();
//    return 1;
//}
