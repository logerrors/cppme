#include <iostream>

struct student {
    int num;
    char name[20];
    int sex;
    int age;
    char address[20];
};

// 自定义 struct 输出
std::ostream& operator <<(std::ostream& out, const struct student& stu){
    return out << "student | num: " << stu.num << " name: " << stu.name << " sex: " << stu.sex << " age: " << stu.age << " address: " << stu.address;
}

// 自定义 struct 输入
std::istream& operator >>(std::istream& in, struct student& stu){
    return in >> stu.num >> stu.name >> stu.sex >> stu.age >> stu.address;
}


int main(int argc, char const *argv[])
{
    struct student xiaoming = {
        .num = 234,
        .name = "xiaoming",
        .sex = 1,
        .age = 17,
        .address = "beijing"
    };

    std::cout << xiaoming << std::endl;

    struct student xiaohong;
    std::cin >> xiaohong;

    std::cout << xiaohong << std::endl;
    return 0;
}
