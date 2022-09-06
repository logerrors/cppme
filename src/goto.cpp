#include "icecream.hpp"



void sum(int a, int b, int* c){
    auto result = new int;

    if(a + b > 10){
        *result = -1;
        goto freeme; // 通过 goto 来资源释放, 需要注意的是, goto 不能跨函数使用
    }else{
        *result = a + b;
    }
    
freeme:
    *c = *result;
    delete result;
}

int main(int argc, char const *argv[])
{
    int a;
    int b;
    int c;
    scanf("%d %d", &a, &b);
    sum(a, b, &c);
    IC(c);
    return 0;
}
