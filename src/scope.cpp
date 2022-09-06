#include <stdio.h>

// 变量有作用域
// 同一个函数内部的 {} 只是编译器整的一个手段, 实际上都是在一个函数栈内

// static 修饰局部变量, 生命周期存在于 .data 段
// static 修饰全局变量, 作用域存在于单个 object 文件内, 生命周期存在于 .data 段
// static 修饰函数, 作用域存在于单个 object 文件内
// 局部变量生命周期为整个栈帧


static int s_a = 22;

int main(int argc, char const *argv[])
{
    int* p_a = nullptr;

    printf("s_a: %d \n", s_a);

    {
        int aaaaa = 23;
        p_a = &aaaaa;
    }

    {
        // int b = a; 这一句会报错
        int bbbbbb = *p_a; // 这一句不会
        printf("%d \n", bbbbbb);
    }

    {
        static int s_a = 23;
        printf("s_a: %d\n", s_a);
    }


    {
        static int s_a = 25; // 不同块内的静态局部变量也是隔离的
        printf("s_a: %d\n", s_a);
    }

    return 0;
}
