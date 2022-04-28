//
// Created by 18041 on 2022/3/31.
//

#include "chapter5.h"
#include <iostream>

using namespace std;

class People {
public:
    People(char *name, int age);

    virtual void display();

protected:
    char *m_name;
    int m_age;
};

People::People(char *name, int age) : m_name(name), m_age(age) {}

void People::display() {
    cout << m_name << "今年" << m_age << "岁了，" << "是个无业游民" << endl;
}


class Teacher : public People {
public:
    Teacher(char *name, int age, int salary);

    virtual void display();

protected:
    int m_salary;
};

Teacher::Teacher(char *name, int age, int salary) : People(name, age), m_salary(salary) {

}

void Teacher::display() {
    cout << m_name << "今年" << m_age << "岁了，" << "是个教师，每月收入为：" << m_salary << endl;
}

void testAA() {
    People *p = new People("王小二", 23);
    p->display();
    p = new Teacher("李二狗", 24, 6000);
    p->display();
}

void testBB() {
    People p("王小二", 23);
    Teacher t("李二狗", 46, 8300);
    People &rp = p;
    People &rt = t;

    rp.display();
    rt.display();
}

class Line {
public:
    Line(float len);

    virtual float area() = 0;

    virtual float volume() = 0;

protected:
    float m_len;
};

Line::Line(float len) : m_len(len) {

}

class Rec : public Line {
public:
    Rec(float len,float width);
    float area();

protected:
    float m_width;

};
Rec::Rec(float len,float width):Line(len),m_width(width){

}

float Rec::area() {
    return m_len*m_width;
}
//长方体
class Cuboid : public Rec {
public:
    Cuboid(float len,float width,float height);
    float area();
    float volume();

protected:
    float m_height;
};


Cuboid::Cuboid(float len,float width,float height):Rec(len,width),m_height(height){

}

float Cuboid::area() {
    return 2*(m_len*m_width+m_len*m_height+m_width*m_height);
}
float Cuboid::volume() {
    return m_len*m_width*m_height;
}

void testCC(){
    Line *p = new Cuboid(10,20,30);
    cout<<"The area of Cuboid is "<<p->area()<<endl;
}

//typeid使用

class Base{};
struct  STU{};

void testDD(){
    Base base;
    const type_info &info = typeid(base);
    int n = 100;
    const type_info &intInfo = typeid(n);
    cout<<"int type_info:"<<intInfo.name()<<","<<intInfo.hash_code()<<endl;
    cout<<"base type_info:"<<info.name()<<","<<info.hash_code()<<endl;
}

void testEE(){
    char *str ;
    int a = 2;
    int b = 10;
    float c;
    bool ff = typeid(int ) == typeid(int);
    bool ee = typeid(char *) == typeid(char);
    bool gg = typeid(a) == typeid(int);
    cout<<ff<<ee<<gg<<endl;
}

//int main() {
//    testEE();
//    return 1;
//}