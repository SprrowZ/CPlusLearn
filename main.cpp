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
            printf("%s��������%d,�ɼ���%f\n", name, age, score);
        }
    };
}

void demoString() {
    using  namespace std;
    string str;
    int age;
    cin>>str>>age;
    cout<<str<<"�Ѿ�����"<<age<<"���ˣ�"<<endl;

}

//int main() {
//    std::cout << "Hello, World!s" << std::endl;
//    Diy::Student stu1;
//    stu1.name = "С��";
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
    std::printf("Hello��");
}

void cDemo() {
    printf("��ð�~");
}

