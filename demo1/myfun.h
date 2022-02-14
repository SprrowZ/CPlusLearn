//
// Created by 18041 on 2022/2/14.
//



//第一种方式

//extern "C" void display();
//void display();
//第二种方式，实际开发中可以使用
#ifdef __cplusplus
extern "C" {
#endif
    void display();
#ifdef  __cplusplus

}

#endif
