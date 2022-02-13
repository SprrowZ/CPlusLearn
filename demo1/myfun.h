//
// Created by 18041 on 2022/2/14.
//

#ifndef UNTITLED1_MYFUN_H
#define UNTITLED1_MYFUN_H
//第一种方式
extern "C" void display();
void display();
//第二种方式，实际开发中可以使用
extern "C" {
    void display();
}

#endif //UNTITLED1_MYFUN_H
