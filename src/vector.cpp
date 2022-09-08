#include <vector>
#include "icecream.hpp"

int main(int argc, char const *argv[])
{
    std::vector<int> res;

   size_t cab = res.capacity();

/*  
每一次分配都会是之前的两倍
ic| i: 0, cab: 0, res.size(): 1, res.capacity(): 1
ic| i: 1, cab: 1, res.size(): 2, res.capacity(): 2
ic| i: 2, cab: 2, res.size(): 3, res.capacity(): 4
ic| i: 4, cab: 4, res.size(): 5, res.capacity(): 8
ic| i: 8, cab: 8, res.size(): 9, res.capacity(): 16
ic| i: 16, cab: 16, res.size(): 17, res.capacity(): 32
ic| i: 32, cab: 32, res.size(): 33, res.capacity(): 64
ic| i: 64, cab: 64, res.size(): 65, res.capacity(): 128
ic| i: 128, cab: 128, res.size(): 129, res.capacity(): 256
ic| i: 256, cab: 256, res.size(): 257, res.capacity(): 512
ic| i: 512, cab: 512, res.size(): 513, res.capacity(): 1024
ic| i: 1024, cab: 1024, res.size(): 1025, res.capacity(): 2048
ic| i: 2048, cab: 2048, res.size(): 2049, res.capacity(): 4096
ic| i: 4096, cab: 4096, res.size(): 4097, res.capacity(): 8192
ic| i: 8192, cab: 8192, res.size(): 8193, res.capacity(): 16384
ic| i: 16384, cab: 16384, res.size(): 16385, res.capacity(): 32768
ic| i: 32768, cab: 32768, res.size(): 32769, res.capacity(): 65536
ic| i: 65536, cab: 65536, res.size(): 65537, res.capacity(): 131072
ic| i: 131072, cab: 131072, res.size(): 131073, res.capacity(): 262144
ic| i: 262144, cab: 262144, res.size(): 262145, res.capacity(): 524288
*/
    for(size_t i = 0 ;i < 1000000; i++){
        res.push_back(i);
        if(cab != res.capacity()){
            IC(i, cab, res.size(), res.capacity());
            cab = res.capacity();
        }
    }

    // 可变的迭代器
    std::vector<int>::iterator iter = res.begin();
    for(;iter != res.end();){
        if(*iter % 100000 == 0){
            *iter = *iter + 1;
            IC(*iter);
        }
        iter++;
    }

    // 不可变的迭代器
    std::vector<int>::const_iterator const_iter = res.cbegin();
    for(;const_iter != res.cend();){
        if(*const_iter % 232323 == 0){
           //  *const_iter = *const_iter + 1;
            IC(*const_iter);
        }
        const_iter++;
    }

    // 反向迭代器
    std::vector<int>::reverse_iterator r_iter = res.rbegin();
    for(;r_iter != res.rend();){
        if(*r_iter % 232323 == 0){
            *r_iter = *r_iter + 1;
            IC(*r_iter);
        }
        r_iter++;
    }

    // 迭代时插入数据会使迭代器失效
    // for(auto it = res.begin(); it != res.end(); it++){
    //     if(*it % 100 == 0){ 
    //         res.insert(it, 2222); // 这里非常危险, 容易造成内存问题, 特别是 vector 内部重新内存分配后, 迭代器会失效
    //     }
    //     std::cout << *it << std::endl;
    // }
    {
        auto it = res.begin();
        std::cout << *it << std::endl; // 1
        it = res.insert(it ,2222); // 在 1 之前插入 2222, 然后返回 2222 的迭代器
        it++;
        std::cout << *it << std::endl; // 1 
        it = res.insert(it ,2222);
        std::cout << *it << std::endl; // 2222
        it++;
        std::cout << *it << std::endl; // 1 
        it++;
        it++;
        std::cout << *it << std::endl; // 2
    }

    // 迭代时插入元素安全的做法
    for(auto it = res.begin(); it != res.end(); it++){
        if(*it % 100 == 0){
            it = res.insert(it, 2222); 
            it++;
        }
        std::cout << *it << std::endl;
    }



    return 0;
}
