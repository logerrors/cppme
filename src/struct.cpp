#include "icecream.hpp"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    icecream::ic.show_c_string(true);

    struct student {
        int num;
        char name[5];
        int sex;
        int age;
        char address[5];
    } wanger;

    struct student zhangsan, lisi; // 先默认初始化
    IC(wanger); // clang > 7 , 这里可以直接进行打印
 
    strcpy(zhangsan.name, "cpp"); // 后面进行赋值
    zhangsan.age = 27;
    zhangsan.sex = 0;
    zhangsan.num = 2323;
    strcpy(zhangsan.address, "suzhou");
    IC(zhangsan);

    struct student xiaohong = { // 定义即初始化
        2,
        "hong",
        1,
        23,
        "suzh"
    };
    IC(xiaohong);

    struct student xiaoming = { // 定义时根据成员变量名称乱序赋值
        .address = "sh",
        .age = 34,
        .sex = 1
    };
    IC(xiaoming);

    struct student students[] = { // 结构体数组
        {1, "x", 1, 23, "bj"},
        {2, "x", 1, 23, "bj"},
        {3, "x", 1, 23, "bj"},
    };

    for(auto i = 0; i < sizeof(students)/sizeof(student);i++){
        IC(students[i].num);
    }

    struct student * p_stu = &students[0]; // 结构体指针

    IC(p_stu->num, p_stu->name, p_stu->sex);
    return 0;
}
