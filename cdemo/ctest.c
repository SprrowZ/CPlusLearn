//
// Created by 18041 on 2022/2/15.
//
#include <stdio.h>
//#include "ctest.h"
//带参数的宏定义,括号很重要！
#define M(y) (y*y+3*y)

#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void demoPointer14() {
    int a = 22, b = 33, c = 99;
    int *arr[3] = {&a, &b, &c};
    //指向指针数组的指针
    int **p = arr;
    printf("%d,%d,%d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d,%d,%d\n", **(p + 0), **(p + 1), **(p + 2));
}

//测试函数指针
int maxValue(int a, int b) {
    return a > b ? a : b;
}

int demoPointer15() {
    int x = 10, y = 12, maxVal;
    int (*pmax)(int, int) = maxValue;
    maxVal = maxValue(x, y);
    printf("maxValue is:%d", maxVal);
}

/******************结构体*******************/
struct Stu {
    char *name;
    int age;
    int num;
    float score;
};
//结构体数组
struct Company {
    char *name;
    float gmv;
    char *location;
} company[8];


void testStruct1() {
    struct Stu stu1, stu2;
    stu1.age = 12;
    stu1.num = 1011;
    stu1.score = 85.5;
    printf("age:%d,num:%d,score:%f", stu1.age, stu1.num, stu1.score);
}

void testStruct2() {
    struct Stu stu1;
    stu1.age = 12;
    stu1.num = 1011;
    stu1.score = 85.5;

    struct Stu *pstu1 = &stu1;
    printf("age:%d,num:%d,score:%f", (*pstu1).age, pstu1->num, stu1.score);
}

struct Fruit {
    char *name;
    char *color;
    int num;
} fruits[] = {
        {"Apple",      "red",    1},
        {"Orange",     "yellow", 2},
        {"Watermelon", "green",  3}
};

void average(struct Fruit *ps, int len);

void testStruct3() {
    int len = sizeof(fruits) / sizeof(struct Fruit);
    average(fruits, len);
}

void average(struct Fruit *ps, int len) {
    for (int i = 0; i < len; ++i) {
        printf("name:%s,color:%s,num:%d\n", (ps + i)->name, (ps + i)->color, (ps + i)->num);
    }
}

void demoEnum() {
    enum week {
        MON, Tues, Wed, Thurs, Fri, Sat, Sun
    }; //枚举默认值从0开始，往后逐个加1
    enum week2 {
        MON2 = 1, Tues2, Wed2
    };

}

//const

void testConst1() {
    const int MaxNum = 10;

    int num1 = 10;
    int num2 = 20;
    const int *p1 = &num1;
    p1 = &num2;
    num2 = 3;
    printf("*p1 value is:%d", *p1);
    int const *p2 = &num2;
    int *const p3 = &num1;
    //p3 = &num2; //报错
}

void testConst2() {
    const char *p1 = "hello!";
    char *p2 = p1;//将const转化为非const，有问题
    printf("p2 value:%s", *p2);
}

void testRand() {
    int a, b;
    srand((unsigned) time(NULL)); //重新播种
    a = rand() % 10;  //产生0~9的随机数
    b = rand() % 51 + 13; //产生13~63的随机数
    printf("随机数：a:%d,b:%d", a, b);
}

void testFile1() {
    FILE *fp = fopen("/Users/zhaozhenguo/Desktop/cdemo.txt", "r");
    int N = 100;
    char str[N + 1];
    if (fp == NULL) {
        printf("Failed to open file!\n");
        exit(0);
    } else {
        printf("Open Success~\n");
        while (fgets(str, N, fp) != NULL) {
            printf("%s", str);
        }

    }
    fclose(fp);
}

//文件读取fgetc
void testFile2() {
    char ch;
    FILE *fp = fopen("/Users/zhaozhenguo/Desktop/cdemo.txt", "r+");
    if (fp == NULL) {
        printf("Fail to open file");
        exit(0);
    }
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    putchar("\n");
    fclose(fp);
}

#define  N  101

void testFile3() {
    FILE *fp;
    fp = fopen("/Users/zhaozhenguo/Desktop/cdemo.txt", "rt");
    if (fp == NULL) {
        printf("Fail to open file");
        exit(0);
    }
//    char *append_content = "i want to fly~";
//    fputs(append_content, fp);
    char content[N + 1];
    while (fgets(content, N, fp) != NULL) {
        printf("%s", content);
    }
    fclose(fp);

}

#define M 3
struct FileStu {
    char name[10];//name
    int num; // number
    int age;//age
    float score;
} boys[M] = {
        "李一", 1, 20, 78.5,
        "王二", 2, 22, 88.5,
        "张三", 3, 24, 99.5
}, boy, *pboys;

void testFile4() {
    FILE *fp;
    int i;
    pboys = boys;
    if ((fp = fopen("/Users/zhaozhenguo/Desktop/cdemo.txt", "wb+")) == NULL) {
        printf("Cannot open file!bizzzzzz~");
        exit(1);
    }
    fwrite(boys, sizeof(struct FileStu), 3, fp);
    fseek(fp, sizeof(struct FileStu), SEEK_SET);//移动位置指针
    fread(&boy, sizeof(struct FileStu), 1, fp);//读取一条学生信息到boy中
    printf("%s %d %d %f\n", boy.name, boy.num, boy.age, boy.score);
    fclose(fp);
}

void realCopyFile(char *readFile, char *writeFile);

void copyFile() {
    char readFile[100];
    char writeFile[100];
    //todo 指定输入输出文件
    realCopyFile(readFile, writeFile);
}

void realCopyFile(char *readFile, char *writeFile) {
    FILE *fpRead;
    FILE *fpWrite;
    int bufferLen = 1024 * 4;
    char *buffer = (char *) malloc(bufferLen);
    int readCount; //实际读取到的字节数
    if ((fpRead = fopen(readFile, "rb")) == NULL || (fpWrite = fopen(writeFile, "wb")) == NULL) {
        printf("Cannot open file");
        exit(1);
    }
    //不断从fileRead读取内容，放在缓冲区，再将缓冲区的内容写入到fileWrite
    while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0) {
        fwrite(buffer, readCount, 1, fpWrite);
    }
    free(buffer);
    fclose(fpRead);
    fclose(fpWrite);
}

//获取文件长度
long fsize(FILE *fp) {
    long n;//文件长度
    fpos_t fpos;
    fgetpos(fp, &fpos);//获取当前文件位置
    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    fsetpos(fp, &fpos);//恢复之前的位置
    return n;
}

//
//int main() {
//    testFile4();
//    return 0;
//}

