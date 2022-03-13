//
// Created by zhaozhenguo on 2022/3/10.
//

#include <iostream>
#include "chapter2.h"

using namespace std;

class Student {
public:
    char *name;
    int age;
    float score;

    void say() {
        cout << name << "的年龄是：" << age << ",成绩是：" << score << endl;
    }
};

void test1() {
    // class Student stu; //class 可省略
    Student stu;//创建对象
    Student stuArr[100]; //创建对象数组
    //在栈上分配内存
    Student *pStu = &stu;
    //在堆上分配内存
    Student *pStu2 = new Student;

//    stu.name = "KuGou~";
//    stu.age = 21;
//    stu.score = 20.5;
//    stu.say();
    pStu2->name = "SingleDog";
    pStu2->age = 27;
    pStu2->score = 20.5;
    pStu2->say();
    delete pStu2;//删除对象

}


class Book {
public:
    char *name;
    char *author;
    float price;

    void logInfo();
};

void Book::logInfo() {
    cout << name << "的作者是：" << author << ",价格是：" << price << endl;
}

void test2() {
    Book *book_fp = new Book;
    book_fp->name = "《麦田守望者》";
    book_fp->author = "杰罗姆";
    book_fp->price = 49.5;
    book_fp->logInfo();
}


class Person {
private:
    char *m_name;
    int m_age;
    float m_score;
    const int m_num;
public:
    Person(int num, char *name, int age, float score); //声明构造函数

    void setName(char *name);

    void setAge(int age);

    void setScore(float score);

    void show();
};

void Person::setName(char *name) {
    m_name = name;
}

void Person::setAge(int age) {
    m_age = age;
}

void Person::setScore(float score) {
    m_score = score;
}

Person::Person(int num, char *name, int age, float score) : m_num(num), m_name(name), m_age(age), m_score(score) {

}

void Person::show() {
    cout << m_name << "的年龄是：" << m_age << ",成绩是：" << m_score << endl;
}

void test3() {
    Person *person = new Person(1, "二狗", 22, 87.5);
//    person->setName("二狗");
//    person->setAge(22);
//    person->setScore(87.5);
    person->show();
}


class VLA {
public:
    static int num;
public:
    VLA(int len);

    ~VLA();

private:
    int *at(int i);//获取第i个元素的指针
private:
    const int m_len;
    int *m_arr;//数组指针
    int *m_p;//指向第i个元素的指针
};

VLA::VLA(int len) : m_len(len) {
    if (len > 0) {
        m_arr = new int[len];
    } else {
        m_arr = NULL;
    }
    int realLen = this->m_len;

}
//析构函数
VLA::~VLA() {
    delete[] m_arr;
}


int main() {
    test3();
    return 1;
}