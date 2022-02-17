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

//指针作为返回值
char *demoPointer10(char *str1, char *str2) {
    if (strlen(str1) > strlen(str2)) {
        return str1;
    } else {
        return str2;
    }
}

void testMethodPointer() {
    char *a = "hello~";
    char *b = "I am Chinese";
    char *result = demoPointer10(a, b);
    printf("%s\n", result);
}

//二级指针
void demoPointer11() {
    int a = 100;
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("a:%d,*p1:%d,**p2:%d,***p3:%d\n", a, *p1, **p2, ***p3);
    printf("p1:%d,*p2:%d,**p3:%d", p1, *p2, **p3);
}

//二维数组指针
void demoPointer12() {
    int a[3][4] = {{0, 1, 2,  3},
                   {4, 5, 6,  7},
                   {8, 9, 10, 11}};
    //指向a的指针变量p
    int (*p)[4];
    p = a;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}


void demoPointer13() {
    char *p = NULL;
    gets(p);
    printf("value:%d", p);
}

void judgePointer(int *p) {
    if (p == NULL) {

    } else {

    }
}
void demoPointer14(){
    int a = 22,b= 33,c =99;
    int *arr[3] = {&a,&b,&c};
    //指向指针数组的指针
    int **p = arr;
    printf("%d,%d,%d\n",*arr[0],*arr[1],*arr[2]);
    printf("%d,%d,%d\n",**(p+0),**(p+1),**(p+2));
}


int main() {
    // printf("value:%d", M(3)/2);
    demoPointer14();
    return 0;
}

