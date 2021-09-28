#include <iostream>
using namespace std;
//declaration
void fun1();
void fun2();
//definition
void fun2()
{
    int y=3;
    cout<<"fun2 reached last line , destroying fun2"<<endl;
}
void fun1()
{
    int x=7;
    cout<<"calling fun2"<<endl;
    fun2();
    cout<<"fun1 reached last line, destroying fun1"<<endl;
}
//all memory allocation is done in stack section
int main()
{   
    int a=9;
    cout<<"calling fun1"<<endl;
    fun1();
    cout<<"main reached last line, destroying main function"<<endl;
    return 0;
}