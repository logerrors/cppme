#include "icecream.hpp"

int main(int argc, char const *argv[])
{

    // 规则 1 , 每个成员的地址按照自身长度对齐
    // 规则 2 , 结构体最终的大小是最长成员的整数倍

    // student1
    struct student1
    {
        int num;         // 0 + 4
        char name[5];    // 4 + 5 + ~3
        int sex;         // 12 + 4
        int age;         // 16 + 4
        char address[5]; // 20 + 5 + ~3  = 25 , 此时最长成员的整数倍为 4 * 7 = 28
    };

    IC(sizeof(struct student1));

#pragma pack(1) // 按照 1 字节对齐, 紧凑式, 不会有间隙
    struct student2
    {
        int num;
        char name[5];
        int sex;
        int age; 
        char address[5];
    };
#pragma pack()
    IC(sizeof(struct student2));

    struct stu
    {
        char sex; // 0 + 1 + ~3
        int length; // 4 + 4 
        char name[10]; // 8 + 10 + ~2 // 18, 4 * 5 = 20
    };
    IC(sizeof(struct stu));
    return 0;
}
