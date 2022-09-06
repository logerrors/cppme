#include "icecream.hpp"

int main(int argc, char const *argv[])
{
    int a;
    int b;

    // 赋值运算符从右往左结合
    a = (b = 1);
    IC(a, b);

    // 逗号表达式
    int x = (4,5);
    IC(x);
    return 0;
}
