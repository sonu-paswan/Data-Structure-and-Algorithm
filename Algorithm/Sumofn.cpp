
// program to find sum of n natural numbers using stack
#include <iostream>
#include <stack>
using namespace std;

int main()
{   stack<int> stack1;
    stack1.push(1);
    printf("how many numbers ? :");
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        stack1.push(stack1.top()+i);
    }
    while(!stack1.empty()){
    printf("%d\n",stack1.top());
    stack1.pop();
    }
    return 0;
}