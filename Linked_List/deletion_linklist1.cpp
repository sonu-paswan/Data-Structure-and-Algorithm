#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *head = NULL;
void createList(int A[], int size)
{
    int i = 0;
    Node *last, *temp;
    head = new Node;
    head->data = A[0]; //creating first node
    head->next = NULL;
    last = head;
    for (int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
// void display(Node *p)
// {
//     while (p)
//     {
//         cout << p->data << " ";
//         p = p->next;
//     }
// }
void display(Node *p)// recursive method 
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}

int main()
{

    int arr[] = {8, 34, 90, 67, 9, 10};
    createList(arr, 6);
    display(head);
    
    ///////////////////// deletion of node ///////////////////

    ///////////////////// deleting first element ///////////
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << endl
         << "after deleting first element " << endl;
    display(head);

    ///////////////////// deleting last element /////////////
    Node *t = head;
    while (t->next->next != NULL)
    {
        t = t->next; //// points to the second last element
    }
    delete t->next;
    t->next = NULL;
    cout << endl
         << "after deleting last element " << endl;
    display(head);

    ///////////////////// deleting in between first element and last element //////////
    int pos = 3;
    Node *tem = head, *anothertemp = NULL;
    // tem = tem->next;
    for (int i = 0; i < pos - 1; i++) //deleting algoritm for in b/w
    {
        anothertemp = tem;
        tem = tem->next;
    }
    anothertemp->next = tem->next;
    delete tem;
    // delete anothertemp->next;
    cout << endl
         << "after deleting third element" << endl;
    display(head);
    return 0;
}
