#include <stdio.h>
#include <stdint.h>
#include "icecream.hpp"


int max(int x, int y){
    return x > y ? x : y;
}


int main(int argc, char const *argv[])
{
    int i = 1;;
    int* p[10]; // 指针数组

    for(int i = 0; i < sizeof(p)/sizeof(int*); i++)
    {
        p[i] = &i; // 10 个指针都指向 i 的地址
    }

    *(p[0]) = 23;

    printf("%d \n", *(p[2]));

    uint8_t image[6][8];

    uint8_t *p_image = (uint8_t*)image;
    for(int i = 0; i < 6 * 8; i++)
    {
        p_image[i] = i;
    }

    IC(image);

    uint8_t (*p_image_array)[8] = (uint8_t(*)[8])image; // 数组指针, 指向的是一个数组, 此指针的 + - 都是按照数组的步长进行移动

    for(int i = 0;i < 6; i++){
        (*p_image_array)[0] = 1;
        p_image_array++;
    }

    IC(image);


    // 函数指针
    // 函数指针, 也能用来作为函数的参数
    auto p_max = (decltype(max)*)max;  // int (*p)(int x, int y)

    int c = (*p_max)(3, 4);
    IC(c);

    char str[] = "hello world";
    char str2[] = "hello";

    const char* p1 = str;
    char* const p2 = str2;

    // const char* 这个指针本身可以动, 但是不可以通过这个指针来变更指向的对象
    printf("p1 : %s \n", p1);
    p1 = str2;
    // p1[1] = 'm';
    printf("p1 : %s \n", p1);

    // char* const 这个指针自己不允许变, 但是可以通过这个指针来变更指向的对象
    printf("str2 : %s \n", str2);
    p2[1] = 'm';
    // p2 = str;
    printf("str2 : %s \n", str2);
    return 0;
}
