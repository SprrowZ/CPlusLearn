//
// Created by zhaozhenguo on 2022/3/10.
//

#include <iostream>
#include <string>
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
    VLA(int len);

    ~VLA();

public:
    static int num;

    static int getNum();

    int *getItemPointer() const;

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

int VLA::getNum() {
    return num;
}

int VLA::num = 10;

int *VLA::getItemPointer() const {
    return m_p;
}

class TeamLeader;

class Manager {
public:
    Manager(int num, char *name);

public:
    void show(TeamLeader *ptl);

private:
    int m_num;
    char *m_name;
    char *province;

};

class TeamLeader {
public :
    TeamLeader(char *name, int num);

private:
    char *m_name;
    int m_num;
public:
    friend class Manager;

};


Manager::Manager(int num, char *name) : m_num(num), m_name(name) {
}

TeamLeader::TeamLeader(char *name, int num) : m_name(name), m_num(num) {}

void Manager::show(TeamLeader *ptl) {
    cout << ptl->m_name << "的编号是：" << ptl->m_num;
}

void test4() {
    VLA vla = VLA(10);
    int num = VLA::num;

}

void test5() {

    TeamLeader teamLeader("Wang", 2);
    Manager manager(1, "Li");
    manager.show(&teamLeader);
}

void test6() {
    string s1; //只定义未初始化，编译器会将默认值""赋值给s1
    string s2 = "c plus plus";
    string s3 = s2;
    string s4(5, 's'); //由5个's'组成的字符串
    int s4len = s4.length();

    for (int i = 0; i <s4len ; ++i) {
        cout<<s4[i]<<" ";
    }
    s2.insert(7,"amazing~");
    //删除字符串
    s2.erase(0,2);
   int index =  s2.find('p',3);
   int index2 = s2.find_first_of('s',5);
   int index3 = s2.rfind('s',10);
}


int main() {
    test5();
    return 1;
}