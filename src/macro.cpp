#include <stdio.h>


// 那种只用到一次的字面量, 就别用宏了, 没什么意义
#define PI 3.14
#pragma message("define pi")
#undef PI // 去掉这个宏

#ifndef PI
#pragma message("define pi")
#define PI 3.14
#endif

#ifdef PI
#pragma message("unset pi")
#undef PI
#endif

// 我一般用 progma 观察编译时是否开启了某个 feature
#pragma message("why not display progma message")

#define MAX(a, b)   (a)>(b)?(a):(b)

#define STR(x) #x

#define CAT(a, b) a##b

#define CPP98 1998
#define CPP03 2003
#define CPP11 2011
#define CPP14 2014
#define CPP17 2017


// 通过宏来预处理代码
// c++ 标准 03, 98, 11, 14, 17
// 构建类型 debug, release
// 构建的架构 x86, arm, risc-v
// 构建的系统 win, macos, linux
// 需要开启的一些 feature, 如 WITH_CUDA, WITH_OPENCV
// 需要关闭的一些 feature, 如 WITHOUT_GPU, WITHOUT_NPU

int main(int argc, char const *argv[])
{
    printf("max: %d \n", MAX(3, 4));
    printf("str: %s \n", STR(hello world));
    printf("source location: %d \n", CAT(12, 34));

#ifdef DEBUG
    printf("debug xxx\n");
#else
    printf("production xxx\n");
#endif

#define STD CPP11

#if STD==CPP03
    printf("cpp03\n");
#elif STD==CPP11
    printf("cpp11\n");
#else
    printf("cpp unknow std\n");
#endif
    return 0;
}
