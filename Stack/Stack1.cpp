#include <iostream>
using namespace std;

// object oreinted stack implementation
class Stack
{
private:
    int size;
    int top;
    int *arr = NULL;

public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[this->size];
    }
    void push(int data);
    void Display();
    bool is_Empty();
    bool is_Full();
    int pop();
    int Peek();
    void displayFull();
};
void Stack::push(int data) //add element to last
{
    if (is_Full())
        cout << "stack overflow" << endl;
    else
    {
        arr[++top] = data;
    }
}
void Stack::Display()
{
    if (is_Empty())
        cout << "Stack is empty" << endl;
    else
    {
        int temp = top;
        while (temp != -1)
        {
            cout << arr[temp] << " ";
            temp--;
        }
        cout << endl;
    }
}
bool Stack::is_Empty() //returns true if stack is empty else false
{
    return (top < 0); // (operator < )returns boolean value
}
bool Stack::is_Full(){
    return (top>=size-1);
}
int Stack::pop() //deletes top element
{
    int x = 0;
    if (top < 0)
        cout << "underflow Stack" << endl;
    else
    {
        x = arr[top];
        arr[top] = 0;
        top--;
    }
    return x;
}

int Stack::Peek() //gives top element
{
    if (is_Empty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return arr[top];
}
void Stack::displayFull()
{
    int t = size;
    while (t--)
    {
        cout << arr[t] << " ";
    }
    cout << endl;
}
int main()
{
    Stack Obj(5);
    Obj.push(45);
    Obj.push(40);
    Obj.push(105);
    Obj.push(25);
    Obj.push(4);
    Obj.Display();
    cout<<"deleting "<<Obj.pop()<<endl;
    Obj.Display();

    return 0;
}