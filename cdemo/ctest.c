//
// Created by 18041 on 2022/2/15.
//
#include <stdio.h>
//#include "ctest.h"
//带参数的宏定义,括号很重要！
#define M(y) (y*y+3*y)


void demoPointer1() {
    int a = 1;
    char str[20] = "hello~";
    printf("%#X,%#x\n", &a, str);
}

//指针变量
void demoPointer2() {
    float a = 99.5, b = 20.2;
    int *p = &a;
    int *p2 = &b;
    printf("*p value:%d,*p2 value:%d\n", p, p2);
    p = &b;
    p2 = &a;
    printf("*p value:%d,*p2 value:%d", p, p2);
}

//通过指针变量获取数据
void demoPointer3() {
    float a = 19.5;
    float *p = &a;
    printf("a value: %f, p value: %d,*p value :%f", a, p, *p);
}

void demoPointer4() {
    int a = 15, b = 99, c = 21;
    int *p = &a;
    *p = b;
    c = *p;
    printf("%d,%d,%d,%d,", a, b, c, *p);
}

void demoPointer5(){
    int a =55;
    int *p;
    p =&a;
    printf(" &a:%d,*&a:%d,&*p:%d,p:%d,*p:%d",&a,*&a,&*p,p,*p);
}
//数组指针
void demoPointer6(){
    int arr[] = {55,21,32,16,2};
    int len = sizeof(arr)/ sizeof(int);//数组长度
    int i;
    for (i = 0; i <len ; ++i) {
        printf("%d ",*(arr+i));
    }
}


int main() {
    //printf("value:%d", M(3)/2);
    demoPointer6();
    return 0;
}

