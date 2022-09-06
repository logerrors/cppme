#include "icecream.hpp"

// 传入的实际上是数组地址, 可以理解为指针
int sum(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+=a[i];
    }
    return sum;
}

// 测试一下函数栈的最大值
// 自己的机器上测出来是 ic| n: 27561 这样一个值
// 环境是 rockey linux 9
// gcc 11.2.1
// debug 
int max_recusive(int n){
    IC(n);
    max_recusive(n+1);
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    IC(sum(a, sizeof(a)/sizeof(int)));

    max_recusive(1);
    return 0;
}
