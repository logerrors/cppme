#include "icecream.hpp"

class Base{
public:
    Base() = default;
    ~Base() = default;
    virtual void echo()  {
        printf("Base echo\n");
     }
};

class Child: public Base {
    public:
        Child() = default;
        ~Child() = default;
    void echo() {
        printf("Child echo\n");
    }
};


int fake(int& hello){
    return hello;
}


int fake(int* hello){
    return *hello;
}

int main(int argc, char const *argv[])
{
    icecream::ic.show_c_string(true);
    double f = 100.34f;
    int i = (int)f;
    // 相关类型转换, double -> int
    int i2 = static_cast<int>(f);

    // 子类转成父类
    Child clid;
    auto parent = static_cast<Base>(clid);
    clid.echo();

    // void* 与其他类型指针的转换
    // 不能用于指针类型之间的转换
    void* raw_p = malloc(sizeof(int));

    int* int_p = static_cast<int*>(raw_p);
    *int_p = 23;
    printf("int_p  %d \n", *int_p);


    // 父类转换为子类, 失败
    Base base;
    auto child = dynamic_cast<Child*>(&base);
    if(child == nullptr){
        printf("dynamic_cast failed!!\n");
    }else{
        printf("dynamic_cast ok!!\n");
        child->echo();
    }

    // 父类转换为子类, 成功
    Base* bb = new Child();
    auto bb_child = dynamic_cast<Child*>(bb);
    if(bb_child == nullptr){
        printf("dynamic_cast failed!!\n");
    }else{
        printf("dynamic_cast ok!!\n");
        bb_child->echo();
    }
    delete bb;

    // 去除 const
    const int ai = 90;
    const int& ai_ref = ai;

    //fake(ai_ref);
    fake(const_cast<int&>(ai_ref)); // 去掉引用中的 const 属性
    fake(const_cast<int*>(&ai)); // 去掉指针中的 const 属性


    // 最强大的 reinterpret_cast
    
    // 一个整型转换为指针, 从指针转换为整型
    // 一种类型指针转换为另外一种类型指针, 按照转换后的类型重新解释内存中的内容
    int big_i = 10;
    int* bag_i_p = &big_i;
    unsigned long long p2 = reinterpret_cast<unsigned long long>(bag_i_p);
    printf("%p %llx \n", bag_i_p, p2);

    return 0;
}
