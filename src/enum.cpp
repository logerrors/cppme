#include "icecream.hpp"


int main(int argc, char const *argv[])
{
    enum color { // 默认从 0 开始
        RED,
        GREEN,
        BLUE,
        YELLOW,
        MAX
    };

    // 枚举值本身并不能计算, 可以认为是一个 only read 的值
    for(int i = RED; i < MAX; i++){
        printf("%d\n", i);
    }

    enum version {
        alpha = 1,
        beta = 5,
        stable = 20
    };

    enum version v1 = alpha;
    printf("%d \n", v1);
    return 0;
}
