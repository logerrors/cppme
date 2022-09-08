#include <stdio.h>

int g_i = 25;
int g_i_uinit;

int main(int argc, char const *argv[])
{
    int local = 23;
    int local_uinit;
    static int local_static = 25;
    static int local_static_uinit;
    int* heap_i = new int;

// g_i: 0x404034 g_i_uinit: 0x404040 local: 0x7ffec01c6dcc local_uinit: 0x7ffec01c6dc8 local_static: 0x404038 local_static_uinit: 0x404044 heap_i: 0x1de8eb0
    printf("g_i: %p g_i_uinit: %p local: %p local_uinit: %p local_static: %p local_static_uinit: %p heap_i: %p\n", &g_i, &g_i_uinit, &local, &local_uinit, &local_static, &local_static_uinit, heap_i);

    delete heap_i;
    return 0;
}

/*
stack
heap
global memory/ static memory
.text
*/