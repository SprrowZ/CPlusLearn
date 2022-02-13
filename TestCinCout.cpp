//
// Created by 18041 on 2022/2/13.
//

#include <iostream>

using namespace std;

void demo() {
    int x;
    float y;
    cout << "Please input an int number" << endl;
    cin >> x;
    cout << "The input number is x=" << x << endl;
    cout << "Please input a float number:" << endl;
    cin >> y;
    cout << "The float number is:" << y << endl;

    cin >> x >> y;
    cout << "x value = " << x << "y value = " << y << endl;
}


void demoBool() {
    bool x;
    cout << "Please input bool x value:" << endl;
    cin >> x;
    cout << "x value:" << x << endl;
    x = true;
    cout << "new x value:" << x << endl;
}

void demoConst() {
//    const int m = 10;
//    int n = m;
    const int n = 10;
    int *p = (int *) &n;
    *p = 99;
    printf("%d\n", n);
}
//测试extern 和const关键字
extern int n;

void func() {
    printf("module:%d\n", n);
}

//
void testMalloc() {
    int *p = (int*) malloc(sizeof(int)*10);//分配10个int型内存空间
    free(p);//释放内存
}
void testNewAndDelete(){
    int *p = new int; //分配一个int型的内存空间
    delete p; //释放内存

    int *d = new int[10];//分配10个int型的内存空间
    delete[] p;

}

inline void swap(int *a,int *b){
    int temp;
    temp =*a;
    *a =*b;
    *b =temp;
}
void executeInlineSwap(){
    int m,n;
    cin>>m>>n;
    cout<<m<<","<<n<<endl;
    swap(&m,&n);
    cout<<m<<","<<n<<endl;
}


void demoDeclareDefaultValue(int x = 1,int y =3){
    cout<<x<<y;
}

//可重复声明同一个函数
void demoDeclareOne(int a,int b ,int c =36);
void demoDeclareOne(int a,int b = 2,int c);

void demoDefaultValue(int a,float b= 1.0,bool c = false){
    cout<<"a,b,c value = "<<a<<b<<c;
}


void func(char ch){
    cout<<"#1"<<endl;
}

void func(int n){
    cout<<"#2"<<endl;
}

void func(long m){
    cout<<"#3"<<endl;
}

void func(double f){
    cout<<"#4"<<endl;
}

void testOverloading(){
    short  s = 99;
    float  f =84.6;
    func('a');//不需要类型转换，调用func(char)
    func(s);//将short转换成int，调用func(int)
    func(49);//不需要类型转换，调用func(int)
    func(f);//将float转换成double，调用func(double)
}

//int main() {
//    //demo();// demoBool();//func();//executeInlineSwap();
//    testOverloading();
//    return 0;
//}

