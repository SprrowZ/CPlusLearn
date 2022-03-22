//
// Created by 18041 on 2022/3/16.
//

#include "chapter4.h"
#include <iostream>

using namespace std;

class People {
public:
    void show();
protected:
    char *m_name;
    int m_age;

};
void  People::show() {
 cout<<m_name<<"的年龄是："<<m_age<<endl;
}

class Student : public People {
public:
   void learning();
public:
    using People::m_name;//将protected改为public
    using People::m_age; //将protected改为public
    float m_score;
private:
    using People::show; //将public改为private
};

void Student::learning() {
    cout<<"我是："<<m_name<<",今年"<<m_age<<"岁，这次考了"<<m_score<<endl;
}

void testX() {
    Student stu;
    stu.m_name = "小明";
    stu.m_age = 16;
    stu.m_score = 99.5f;
    //stu.show();//compile error
    stu.learning();
}


class Human{
protected:
    char *m_name;
    int m_age;
public:
    Human(char *,int);

};
Human::Human(char * name, int age):m_name(name),m_age(age) {}

class Child:public Human{
private:
    float m_score;
public:
    Child(char*,int ,float);
    void display();
};

Child::Child(char *name,int age,float score):Human(name,age),m_score(score){

}
void Child::display() {
    cout<<m_name<<"的年龄是："<<m_age<<",其成绩为："<<m_score<<endl;
}
void testY(){
    Child child("二狗",12,87.5);
    child.display();
}


int main() {
    testY();
    return 1;
}




