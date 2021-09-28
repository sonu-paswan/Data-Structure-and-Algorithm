#include <iostream>

using namespace std;
struct DNode
{
    DNode *prev;
    int data;
    DNode *next;
} *head = NULL, *tail = NULL;
void swap(int *a, int *b) //swaping function
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void CreateDLL(int A[], int n) //creating doubly linked list function
{
    head = new DNode;
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;
    DNode *last = head;
    DNode *temp = NULL;
    for (int i = 1; i < n; i++)
    {
        temp = new DNode;
        temp->data = A[i];
        temp->prev = last;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void DisplayWithLinks(DNode *ptr) //display function with pointers info
{
    while (ptr)
    {
        cout << "link :" << ptr << "  Data :" << ptr->data << "  prev :" << ptr->prev << "  next :" << ptr->next << endl;
        ptr = ptr->next;
    }
    cout << endl;
}
void Display(DNode *p) //display function
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Insertion(DNode *p, int position, int DATA) //insertion function for DLL
{

    if (position == 0)
    {
        DNode *newNode = new DNode;
        newNode->data = DATA;
        newNode->prev = NULL;
        newNode->next = p;
        p->prev = newNode;
        head = newNode;
    }
    else
    {
        DNode *temp = p;
        DNode *newNode = new DNode;
        newNode->data = DATA;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}
int Deletion(DNode *ptr, int POS) //deletion function for DLL
{
    int x = 0;
    if (POS == 1)
    {

        head = ptr->next;
        x = ptr->data;
        if (head) //checking
            ptr->next->prev = NULL;
        delete ptr;
    }
    else
    {
        DNode *temp = ptr;
        for (int i = 0; i < POS - 1; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next) //checking
            temp->next->prev = temp->prev;
        x = temp->data;
        delete temp;
    }
    return x;
}
bool LinearSearch(DNode *ptr, int key) //Searching function in DLL
{
    DNode *temp = ptr;
    while (temp)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}
void ReverseLink(DNode *p) //reversing function function (swaping links)
{
    DNode *temp = NULL;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL) //giving last position to head(it will not execute last entry)
        {
            head = p;
        }
    }
}
DNode *Givelast(DNode *p) //gives the last pointer address
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}
void ReverseData(DNode *first, DNode *last) //reversing list by swaping data
{
    while (first != last)
    {
        swap(&first->data, &last->data);
        first = first->next;
        last = last->prev;
    }
}
int Count(DNode *p) //count number of nodes
{
    int a = 0;
    while (p != NULL)
    {
        p = p->next;
        a++;
    }
    return a;
}
void DisplayFromLast(DNode *l) //display function from tail Node
{
    while (l)
    {
        cout << l->data << " ";
        l = l->prev;
    }
    cout << endl;
}
int main()
{
    int arr[] = {2, 3, 7, 8, 9, 6, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    CreateDLL(arr, len);
    cout << "Initial Double Linked List\n";
    DisplayWithLinks(head);
    DNode *last = Givelast(head);
    int length = Count(head);
    ReverseData(head, last);
    cout << "after reversing doubly Linked List" << endl;
    DisplayWithLinks(head);

    return 0;
}
