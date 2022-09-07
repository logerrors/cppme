#include "icecream.hpp"


namespace hello {
    void hello_world(){
        IC("namespace hello");
    }
}

namespace world {
    void hello_world(){
        IC("namespace hello");
    }
}


int main(int argc, char const *argv[])
{
    icecream::ic.show_c_string(true);
    hello::hello_world();
    world::hello_world();
    return 0;
}
