#include <iostream>
#include <vector>
using namespace std;
//// program to reverse a linked list in cpp ////
struct Node
{
    int data;
    Node *next;
} *head = NULL;

void CreateList(int A[], int n)
{
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    Node *last = head, *temp = NULL;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void Display(Node *ptr)
{
    while (ptr != NULL)
    {
        cout<<"link :" <<ptr<<"   Data :"<< ptr->data<<"   next :"<<ptr->next<<"\n";
        ptr = ptr->next;
    }
    cout << endl;
}
int CountList(Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}
/////////////////////////////// reversing linked list by reversing it's element ///////////////////////////

void ReverseList(Node *p, int n)
{
    vector<int> myTempArr; //using vector for reversing Linked List
    int num;
    for (int i = 0; p != NULL; i++) //copying
    {
        num = p->data;
        myTempArr.push_back(num);
        p = p->next;
    }
    p = head;
    for (int i = n - 1; i >= 0; i--) //reversing
    {
        p->data = myTempArr[i];
        p = p->next;
    }
}
Node *ReverseLink(Node *p)
{
    Node *Next = NULL;
    Node *Current = p;
    Node *Prev = NULL;
    while (Current != NULL)
    {
        Next=Current->next;
        Current->next=Prev;
        Prev=Current;
        Current=Next;
    }

    return Prev;
}
// Node *ReverseLink(Node *p)
// {
//     Node *Next = p;
//     Node *Current = NULL;
//     Node *prev = NULL;
//     while (Next != NULL)
//     {
//         prev = Current; 
//         Current = Next;
//         Next = Next->next;
//         Current->next = prev;//reversing
//     }

//     return Current;
// }
int main()
{
    int arr[] = {3, 2, 5, 7, 9, 6, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    CreateList(arr, len);
    cout<<"head :"<<head<<endl;
    Display(head);
    // int n = CountList(head);

    // ReverseList(head,n);

    head = ReverseLink(head); //reversing link and return the address of new link node
    cout<<"after reversing linked list"<<endl;
    cout<<"head :"<<head<<endl;
    Display(head);
    return 0;
}