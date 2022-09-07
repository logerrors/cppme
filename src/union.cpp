#include "icecream.hpp"

int main(int argc, char const *argv[])
{
    union myunion {
        int carnum;
        char cartype;
        char cname[20];
    };

    struct mystruc{
        int carnum;
        char cartype;
        char cname[20];
    };

    union myunion u;
    struct mystruc s;

    IC(sizeof(union myunion)); // 最大的 cname 20
    IC(sizeof(struct mystruc));  // 为什么是 28 ?

    // union 的这些地址都是一样的
    printf("%p %p %p %p \n", &u, &u.carnum, &u.cartype, &u.cname); // 0x7ffedeee4a38 0x7ffedeee4a38 0x7ffedeee4a38 0x7ffedeee4a38

    // struct 成员变量会有偏移
    printf("%p %p %p %p \n", &s, &(s.carnum), &(s.cartype), &(s.cname)); // 0x7ffedeee4a18 0x7ffedeee4a18 0x7ffedeee4a1c 0x7ffedeee4a1d

    struct mystruc s_arr[2];

    printf("%p %p \n", &(s_arr[0]), &(s_arr[1]));


    return 0;
}
