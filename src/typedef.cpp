#include "icecream.hpp"


int max(int x, int y){
    return x > y ? x : y;
}


int main(int argc, char const *argv[])
{
    typedef int NUM[100]; // int 数组类型

    NUM n;
    IC(sizeof(n));

    typedef char * PSTRING; // 字符串指针类型

    PSTRING str = "hello world";
    printf("%s \n", str);

    typedef int (*POINTER_F)(int, int); // 函数指针类型

    POINTER_F f_p = max;
    IC(f_p(3 ,4));
    return 0;
}
