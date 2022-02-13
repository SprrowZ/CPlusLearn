#include <iostream>

#include <cstdio>
#include<string>

using namespace std;

namespace Diy {
    class Student {
    public:
        char *name;
        int age;
        float score;
    public:
        void say() {
            printf("%s的年龄是%d,成绩是%f\n", name, age, score);
        }
    };
}

void demoString() {
    using  namespace std;
    string str;
    int age;
    cin>>str>>age;
    cout<<str<<"已经成立"<<age<<"年了！"<<endl;

}

//int main() {
//    std::cout << "Hello, World!s" << std::endl;
//    Diy::Student stu1;
//    stu1.name = "小明";
//    stu1.age = 22;
//    stu1.score = 87;
//    stu1.say();
//    demoString();
//    return 0;
//}
int n =10;
void func();
void demoDeclareDefaultValue(int x=1,int y=2);

void stdDemo() {
    std::printf("Hello啊");
}

void cDemo() {
    printf("你好啊~");
}

