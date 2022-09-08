 int max(int a, int b){
    return a > b ? a : b;
}

void test(int argc)
{
    int && r_ref= 23;
    int i = 23;
    int & l_ref = i;

    l_ref = 22;
    i = 22;
    // max 这个函数在汇编层面相当于直接内嵌在 test 的代码段里面了,不会有函数栈帧的压栈,出栈
    // 内联的函数过多, 也会造成代码膨胀的问题
    int m = max(argc, 4);
}

int main(int argc, char const *argv[])
{
    test(argc);
    return 0;
}
