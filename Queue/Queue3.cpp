#include <iostream>
#include <stack>
using namespace std;

// Queue implementatiom using stack data structure
struct Queue
{
    stack<int> stack1;
    stack<int> stack2;
};
void enqueue(Queue *, int);
int dequeue(Queue *);
bool isEmpty(Queue *);

void enqueue(Queue *Q, int data)
{
    Q->stack1.push(data);
}
int dequeue(Queue *Q)
{
    int x = -1;
    if (isEmpty(Q))
    {
        cout << "Queue is empty\n";
        return x;
    }
    if (Q->stack2.empty())
    {
        while (!Q->stack1.empty())
        {
            Q->stack2.push(Q->stack1.top());
            Q->stack1.pop();
        }
    }
    x = Q->stack2.top();
    Q->stack2.pop();
    return x;
}
bool isEmpty(Queue *Q)
{
    if (Q->stack1.empty() && Q->stack2.empty())
        return true;
    else
        return false;
}
void Display(Queue *Q)
{
    while (!isEmpty(Q))
    {
        cout << dequeue(Q) << " ";
    }
    cout << endl;
}
int main()
{
    Queue *Q = new Queue;
    enqueue(Q, 23);
    enqueue(Q, 22);
    enqueue(Q, 90);
    enqueue(Q, 12);
    enqueue(Q, 23);
    enqueue(Q, -9);
    enqueue(Q, 0);
    enqueue(Q, 134);
    enqueue(Q, 120);
    Display(Q);
    return 0;
}

// I used c++ because i wanted big size stacks;