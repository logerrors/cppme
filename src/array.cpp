#include "icecream.hpp"
#include <array>
#include <string.h>

int main(int argc, char const *argv[])
{
    {
        int a[5] = {1, 2, 3 ,4, 5};
        IC(a);
    }

    {
        int a[5] = {1, 2, 3}; // 没赋值的都默认为 0
        IC(a);
    }

    {
        int a[2][2] = {{1,2}, {3,4}}; // 为连续的栈上空间
        printf("%p %p %p %p \n", &a[0], &a[1], &a[2], &a[3]);
    }

    {
        std::array<int, 4> a = {1,2,3,4}; // c++ 写法的数组
        IC(a);
    }

    {
        std::array<std::array<int, 2>, 2> a= {{{1,2}, {3, 4}}}; // 这里的初始化方法比较的奇怪, 多了一个 {}
        IC(a);
    }

    {
        std::array<std::array<int, 2>, 2> a= {1, 2 , 3, 4}; // 也可以用这种一维的方式初始化
        IC(a);
    }

    {
        char c[] = {"hello world"}; // 自动补一个 \0
        IC(c);
    }

    {
        char c[12] = "hello world";
        IC(c);
    }

    {
        char c[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'}; // 这种初始化方法并不会自动加 \0
        IC(c);
    }

    {
        char c[20];
        // 如果输入 hello world, 那么实际上只会有 hello , 另外 hello 后面的值均是随机值
        // 尤其需要注意的是输入进来的字符是不会自动补 0 的
        scanf("%s", c); 
        IC(c);
    }

    {
        char c[20] = {0};
        char space[] = " ";
        char d[20] = {0};
        // 输入 hello world , 需要用两个字符数组接收
        scanf("%s %s", c, d); 
        IC(c, d);
        strcat(c, space);
        strcat(c, d);
        IC(c);
    }

    {
        char str[] = "hello world";
        puts(str);
    }

    {
        char hello[20] = "hello ";
        char world[] = "world";
        strcat(hello, world); // world 中的字符串拼接到 hello 中
        IC(hello);
    }

    {
        char c[20] = {0};
        char d[] = "hello world";
        strcpy(c, d); // 用 d 中的字符串覆盖掉 c
        IC(c);
    }

    {
        char c[] = "hello";
        char d[] = "hello";
        assert(strcmp(c, d) == 0);
    }

    {
        // sizeof 是计算类型占据的大小, 编译期就能确定了
        // strlen 是计算字符串的长度, 遇到 0 就截止,  运行期才能确认
        char c[] = "hello world";
        char cc[20] = "hello world";
        const char* ccc = "hello world";
        IC(strlen(c), sizeof(c));
        IC(strlen(cc), sizeof(cc));
        IC(strlen(ccc), sizeof(ccc));
        static_assert(sizeof(const char*) == 8);
    }
    return 0;
}
