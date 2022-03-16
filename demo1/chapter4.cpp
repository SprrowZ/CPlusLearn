//
// Created by 18041 on 2022/3/16.
//

#include "chapter4.h"
#include <iostream>

using namespace std;

class People {
public:
    void setname(char *name);

    void setage(int age);

    char *getname();

    int getage();

private :
    char *m_name;
    int m_age;
};

void People::setname(char *name) {
    m_name = name;
}

void People::setage(int age) {
    m_age = age;
}

char *People::getname() {
    return m_name;
}

int People::getage() {
    return m_age;
}


class Student : public People {
public:
    void setscore(float score);

    float getscore();

private:
    float m_score;
};

void Student::setscore(float score) {
    m_score = score;
}

float Student::getscore() {
    return m_score;
}

void testX() {
    Student stu;
    stu.setname("小明");
    stu.setage(22);
    stu.setscore(99.5);
    cout << stu.getname() << "的年龄是：" << stu.getage() << "，成绩是：" << stu.getscore() << endl;
}

int main() {
    testX();
    return 1;
}




