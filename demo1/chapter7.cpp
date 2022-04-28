//
// Created by 18041 on 2022/4/29.
//

#include "chapter7.h"
#include <iostream>

using namespace std;

template  <typename T> void swap(T *a,T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

void testM1(){
    int n1 = 100,n2 = 200;
    swap(&n1,&n2);
    cout<<"n1:"<<n1<<"  n2:"<<n2;
}

int main(){
    testM1();
    return 0;
}