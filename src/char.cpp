#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 类型为字符数组, 表示字符串 存储在 stack, 会自动补 0
    char str1[]  = "hello world"; 

    // 类型为指针, 表示字符串, 存储在 .odata 区域, 会自动补 0
    const char* str2 = "hello world";

    printf("str1 : %s str2: %s \n", str1, str2);
    return 0;
}
