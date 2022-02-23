// use of stack in reversing a string

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
void Reverse(char *a, int n)
{
    stack<char> S; // standard template library 

    for (int i = 0; i < n; i++) // O(n)
    {

        S.push(*(a+i)); // same as S.push(a[i]);

    }
    for (int j = 0; j < n; j++) // O(n)
    {
        a[j] = S.top();
        S.pop();
    }
    // time complexity-> O(n)
}
int main()
{
    char str[] = "Monster";

    Reverse(str, strlen(str));
    printf("%s", str);
}
