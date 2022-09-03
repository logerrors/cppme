#include <algorithm>
#include <numeric>  // c++ 的方式
#include <limits.h> // c 的方式
#include <cxxabi.h>
#include <string.h>

#include "icecream.hpp"

template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void (*)(void *)> own(
#ifndef _MSC_VER
        abi::__cxa_demangle(typeid(TR).name(), nullptr,
                            nullptr, nullptr),
#else
        nullptr,
#endif
        std::free);
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

using namespace std;

#define DETECT_TYPE(x)                              \
    do                                              \
    {                                               \
        IC(sizeof(x));                              \
        IC_("d", std::numeric_limits<x>::max());    \
        IC_("d", std::numeric_limits<x>::min());    \
        IC_("d", std::numeric_limits<x>::lowest()); \
    } while (0)

int main(int argc, char **argv)
{
    // c++ 可以使用 numeric 头文件中的 numeric_limits 获取极值
    // c 可以用 limits.h 中预定义好的宏获取极值
    DETECT_TYPE(int);
    DETECT_TYPE(unsigned int);

    DETECT_TYPE(float);
    DETECT_TYPE(double);

    DETECT_TYPE(char);
    DETECT_TYPE(unsigned char);

    printf("sizeof(char): %d, max: %d , min: %d \n", sizeof(char), SCHAR_MAX, SCHAR_MIN);
    printf("sizeof(unsighed char): %d, max: %d , min: %d \n", sizeof(unsigned char), UCHAR_MAX, 0); // there is no UCHAR_MIN, why ?

    DETECT_TYPE(short);
    DETECT_TYPE(unsigned short);

    DETECT_TYPE(long);
    DETECT_TYPE(long long);
    DETECT_TYPE(unsigned long long);

    // 关于控制进制的字面量
    IC(12);   // 十进制字面量
    IC(012);  // 八进制字面量
    IC(0x12); // 十六进制字面量

    // 控制类型的字面量, 后面的一些 U , L , f 之类的字面量控制符可以连起来用
    // U - unsigned
    // L - long
    // f - float
    IC(type_name<decltype(12U)>());
    IC(type_name<decltype(12UL)>());
    IC(type_name<decltype(12ULL)>());
    IC(type_name<decltype(12L)>());
    IC(type_name<decltype(12LL)>());
    IC(type_name<decltype(12)>());

    IC(type_name<decltype(3.14)>());
    IC(type_name<decltype(3.14f)>());
    IC(type_name<decltype(3E8)>());
    IC(type_name<decltype(3E-8)>());
    IC(type_name<decltype(3E8f)>());

    // 在数轴上表示浮点数, 可以理解为是一个范围很大的点集
    // float 理解为一个点集, double 也可以理解为一个点集, 相比之下 float 的点集更加稀疏一些, 范围小一些 double 更密集一些, 范围大一些
    // float 的有效位数为 6 ~ 7
    // double 的有效位数为 15 ~ 16
    // 给浮点数变量赋值, 个人理解是在这些点集中取一个最接近的数, 所以会有一定的误差
    float af = 1111111.111;
    double bf = 1111111.111;
    printf("af: %.20f, bf: %.20f \n", af, bf);

    float aaf = 1234567898.1234;
    double bbf = 1234567898.1234;
    printf("aff: %.20f, bff: %.20f \n", aaf, bbf);

    // %c 是字符表示
    // %d 是整型表示
    // 同样的内容, 表示的格式不同,打印出来的也就不同
    char c = 'a';
    printf("c: %c %d \n", c, c);

    // str 和 another_str 指向的同一片内存, 这片内存里面专门存放常量的字符串字面量
    // str_stack 存放的字符串是在栈上的
    const char* str = "hello world";
    const char str_stack[] = "hello world";
    const char* another_str = "hello world";
    
    IC(str, str_stack, another_str);
    printf("str: %p str_stack: %p another_str: %p \n", str, str_stack, another_str);

    // 都是字符串, 但实际上是不同的类型
    // str, another_str 是指针类型, 64 位系统上是 8
    // str_stack 是字符数组, sizeof 值为 12
    printf("str: %d str_stack: %d another_str: %d \n", sizeof(str), sizeof(str_stack), sizeof(another_str));

    // 字符串的长度, 通过 strlen 取的是去掉尾部 \0 的结果
    printf("str: %d str_stack: %d another_str: %d \n", strlen(str), strlen(str_stack), strlen(another_str));

    // sizeof 理解为是编译时就确定的值?
    // strlen 长度只计算到 \0 前的字符
    // 字符串的显示也是到 \0 前的字符
    const char str_go[] = "hello \0 world";
    const char str_go_100[100] = "hello \0 world";
    printf("str_go: %d %d %s \n", sizeof(str_go), strlen(str_go), str_go);
    printf("str_go_100: %d %d %s \n", sizeof(str_go_100), strlen(str_go_100), str_go_100);

    // 基础数据类型之间的转化
    /*
        double     <---- float
        long
        unsigned
        int        <---- char, short
    */

    // 浮点转为整型时, 会直接丢弃掉小数部分, 取整数部分, 不会有类似四舍五入的操作
    double a = 23 + 22.222;
    int aa = 23 + 22.222;
    IC(a, aa);

    float aa1 = 23.3f;
    float aa2 = 23.3f;
    double aa3 = 23.3;
    IC(type_name<decltype(aa1 + aa2)>());
    IC(type_name<decltype(aa1 + aa3)>());
    return 0;
}
