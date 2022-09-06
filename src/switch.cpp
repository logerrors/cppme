#include "icecream.hpp"

int main(int argc, char const *argv[])
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    switch (a)
    {
    case 0:
        IC(a);
        break;
    case 1:
        IC(a); // 这里不加 break 的话, default 都会被调用
    default:
        IC(a);
        break;
    }

    printf("-----\n");

    switch (b)
    {
        case 0: // 两个 case 都能触发
        case 1:
            IC(b);
        default:
            IC(b);
            break;
    }

    printf("-----\n");
    
    switch (c)
    {
        case 0:
        {
            IC(c);
        }
        break;
        case 1:
        {
            IC(c);
        }
        break;
        default:
            IC(c);
            break;
    }

    printf("-----\n");

    switch (d)
    {
        case 0:
        {
            IC(d);
        }
        case 1:
        {
            IC(d);
        }
        break;
        default:
            IC(d);
            break;
    }

    return 0;
}
