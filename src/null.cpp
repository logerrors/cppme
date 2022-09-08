#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <cxxabi.h>
#include <memory>

int main(int argc, char const *argv[])
{

    // c 语言中的 NULL 不等价于 c++ 中的 nullptr
    // 注意重载时的陷阱
    if(typeid(NULL) == typeid(nullptr)){
        std::cout << "type: NULL == nullptr" << std::endl;
    }else{
        std::cout << "type: NULL != nullptr" << std::endl; // 1
    }

    // NULL 实际上是 long 0
    if(typeid(NULL) == typeid(long)){
        std::cout << "type: NULL == long" << std::endl; // 1
    }else{
        std::cout << "type: NULL != long" << std::endl;
    }

    // nullptr 独属于一个类型 std::nullptr_t 这个类型只有一个值 nullptr
    if(typeid(nullptr) == typeid(std::nullptr_t)){
        std::cout << "type: nullptr == nullptr_t" << std::endl; // 1
    }else{
        std::cout << "type: nullptr != nullptr_t" << std::endl;
    }
    return 0;
}
