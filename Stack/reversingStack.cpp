#include <iostream>
#include <stack>

//program for reversing a stack

using namespace std;
stack<int> Reverse(stack <int> &S){
    stack<int> newStack;
    while(!S.empty()){
        newStack.push(S.top());
        S.pop();
    }
    return newStack;
}
int main()
{   stack<int> stack1;
    stack<int> stack2;
    stack1.push(12);
    stack1.push(134);
    stack1.push(99);
    stack1.push(169);
    // while(!stack1.empty()){
    //     cout<<stack1.top()<<endl;
    //     stack1.pop();
    // }
    stack2=Reverse(stack1);
    while(!stack2.empty()){
        cout<<stack2.top()<<endl;
        stack2.pop();
    }

    return 0;
}