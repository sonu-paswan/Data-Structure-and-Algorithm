#include <iostream>
using namespace std;
void increament(int *p)
{
    int *ptr=p;
    int a=98;
    ptr=&a;
    *ptr++;
    p=ptr;
}
int main()
{
    int *pointer=NULL;
    int x=90;
    pointer=&x;
    increament(pointer);
    cout<<*pointer<<endl;
    return 0;
}