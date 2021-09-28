#include <iostream>
#include <stack>
using namespace std;
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
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack1.push(data);
            while (!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }
    int dequeue()
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
    int top()
    {
        int x = -1;
        x = stack1.top();
        return x;
    }
    bool isEmpty()
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
        cout << queue.top() << endl;
        queue.dequeue();
    }

    return 0;
}