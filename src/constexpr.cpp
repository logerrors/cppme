#include <iostream>

constexpr int fib(int n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
    // res 的值, 编译期就能确定
    constexpr int res = fib(10);
    return 0;
}
