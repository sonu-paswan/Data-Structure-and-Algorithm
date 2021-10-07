#include <iostream>
#include <stack>
using namespace std;
// implementation of queue using two stacks 
// by making enqueue operation costlier
struct Queue
{
    stack<int> stack1, stack2;
    void enqueue(int data)
    {
        if (stack1.empty())
        {
            stack1.push(data);
        }
        else if (!stack1.empty())
        {
            while (!stack1.empty())//making empty stack 1 and pushing to stack2 
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack1.push(data);//adding new element 
            while (!stack2.empty())//pushing stack2 element back to stack1 after adding new element in stack 1
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }
    int dequeue() // will dequeue from stack1 only 
    {
        int x = -1;
        if (stack1.empty())
        {
            printf("queue is empty");
        }
        else
        {
            x = stack1.top();
            stack1.pop();
        }
        return x;
    }
    // int top()
    // {
    //     int x = -1;
    //     x = stack1.top();
    //     return x;
    // }

    bool isEmpty()//queue  empty function
    {
        return stack1.empty();
    }
};
int main()
{
    Queue queue;
    queue.enqueue(45);
    queue.enqueue(23);
    queue.enqueue(2);
    queue.enqueue(20);
    queue.enqueue(13);
    while (!queue.isEmpty())
    {
        cout << queue.dequeue() << endl;
        // queue.dequeue();
    }

    return 0;
}