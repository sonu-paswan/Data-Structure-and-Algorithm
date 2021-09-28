#include <stdio.h>
/////////////////////////////global variable usage/////////////////////
int x=0;//global variable
int fun(int n)
{
    if(n>0)
    {x++;
        return fun(n-1)+x;
    }
    return 0;
}
/////////////////////////// static variable usage/////////////////////
// int fun(int n)
// {   static int x;
//     if(n>0)
//     {x++;
//         return fun(n-1)+x;
//     }
//     return 0;
// }
int main()
{
    int x=5;
    printf("%d",fun(x));
    return 0;
}