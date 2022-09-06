#include "icecream.hpp"

/* 一个运行的例子
[wuxing@lab cme]$ xmake r var
g: 0x404054, l: 0x7ffd99b7e974, s: 0x404058 , p: 0xadceb0
*/

// 可以很明显的观察到静态局部变量和全部变量地址很是接近, 可以认为是同一块虚拟内存区域
// 局部变量的地址偏大, 在栈的位置
// new 出来的内存地址, 也偏小一点, 在全局变量&静态局部变量的地址上方

/*
kernel
stack
dynamic so & shared_memory
heap
data
odata
text
*/

int g_status = 1;

int main(int argc, char const *argv[])
{
    int l_status = 2;
    static int s_status = 3;
    auto p_i = new int[10000];

    printf("g: %p, l: %p, s: %p , p: %p\n", &g_status, &l_status, &s_status, p_i);
    getchar();
    delete p_i;
    return 0;
}