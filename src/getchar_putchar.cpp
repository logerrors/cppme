#include "icecream.hpp"

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char msg[] = "hello world";

    // putchar 输出单个字符
    for(int i = 0; i < strlen(msg); i++){
        putchar(msg[i]);
    }
    putchar('\n');

    // ctrl d 表示输入结束
    char c = ' ';
    while((c = getchar()) != 'q'){
        putchar(c);
    }

    printf("----------\n");

    {
        int a , b, c;
        scanf("%d %d %d", &a, &b, &c);
        IC(a, b, c);
    }

    // 
    {
        int a , b, c;
        scanf("%d | %d | %d", &a, &b, &c);
        IC(a, b, c);
    }

    return 0;
}
