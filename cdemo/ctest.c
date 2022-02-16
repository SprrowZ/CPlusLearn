//
// Created by 18041 on 2022/2/15.
//
#include <stdio.h>
//#include "ctest.h"
//带参数的宏定义,括号很重要！
#define M(y) (y*y+3*y)

#include <string.h>

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

void demoPointer5() {
    int a = 55;
    int *p;
    p = &a;
    printf(" &a:%d,*&a:%d,&*p:%d,p:%d,*p:%d", &a, *&a, &*p, p, *p);
}

//数组指针
void demoPointer6() {
    int arr[] = {55, 21, 32, 16, 2};
    int len = sizeof(arr) / sizeof(int);//数组长度
    int i;
    for (i = 0; i < len; ++i) {
        printf("%d ", *(arr + i));
    }
}

//数组指针遍历2
void demoPointer7() {
    int arr[] = {13, 23, 12, 21, 48};
    int *p = arr;
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i < len; ++i) {
        printf("%d ", *p++);
    }
    printf("\n");
    int *p2 = arr;
    for (int j = 0; j < len; ++j) {
        printf("%d ", *++p2);
    }
}

//字符串数组
void demoPointer8() {
    char str[] = " i from china";
    char *p = str;
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        printf("%c ", *p++);
    }
}

//字符串常量
void demoPointer9() {
    char *str = "i am chinese";
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        printf("%c ", *(str + i));
    }
}

void swapByInt(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void testSwap() {
    int a = 66, b = 22;
    swapByPointer(&a, &b);
    printf("a:%d,b:%d", a, b);
}

int findMaxValue(int *arr, int len) {
    int maxValue = arr[0];
    for (int i = 0; i < len; ++i) {
        if (*(arr + i) > maxValue) {
            maxValue = *(arr + i);
        }
    }
    return maxValue;
}

void testArrPointer() {
    int arr[] = {21, 19, 66, 77, 34};
    int len = sizeof(arr) / sizeof(int);
    printf("maxValue is %d", findMaxValue(arr, len));
}


int main() {
    //printf("value:%d", M(3)/2);
    testArrPointer();
    return 0;
}

