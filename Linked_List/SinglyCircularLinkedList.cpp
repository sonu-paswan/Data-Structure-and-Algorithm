#include <iostream>
using namespace std;
/// Circular Singly Linked List ///

struct Node
{
    int data;
    Node *next;
} *head = NULL;
void CreateCLL(int A[], int len) //creating SCLL function
{
    head = new Node;
    head->data = A[0];
    head->next = head;
    Node *last = head;
    for (int i = 1; i < len; i++)
    {
        Node *newNode = new Node;
        newNode->data = A[i];
        last->next = newNode;
        newNode->next = head;
        last = newNode;
    }
}
void Display(Node *p) //displaying function
{
    cout << "Displaying Circular Lisked List" << endl;
    Node *temp = p;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != p);
    cout << endl;
}
void DisplayWithLinks(Node *ptr) //displaying with all information
{
    cout << "displaying with links" << endl;
    Node *t = ptr;
    do
    {
        cout << "link :" << t << "    data :" << t->data << "    next :" << t->next << endl;
        t = t->next;
    } while (t != ptr);
}
Node *GiveLastNode(Node *p) //traverse to last Node of SCLL
{
    Node *temp = p;
    do
    {
        temp = temp->next;
    } while (temp->next != p);//condition for last node in scll
    return temp;
}

Node *ReverseLinks(Node *p)
{
    Node *Prev = NULL;
    Node *Current = p; //observe
    Node *Next = NULL;
    do
    {
        Next = Current->next;
        Current->next = Prev;
        Prev = Current;
        Current = Next;
    } while (Current != head);
    p->next=Prev;
    p=Prev;
    return p;
}
int main()
{
    int arr[] = {3, 4, 2, 1, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    CreateCLL(arr, size);
    cout<<"initial SCLL\n";
    DisplayWithLinks(head);

    /// insertion at starting of node ///
    // Node *newNode = new Node;
    // newNode->data = 12;
    // newNode->next = head;
    // Node *temp = GiveLastNode(head);
    // temp->next = newNode;
    // head = newNode;
    // DisplayWithLinks(head);
    ////////////////////////////////////
    /// insertion in between first and last node in scll ///
       int positon =3;
       Node *newNode=new Node;
       newNode->data=30;
       Node *t=head;
       for(int i=0;i<positon-1;i++){
           t=t->next;
       }
       newNode->next=t->next;
       t->next=newNode;
       cout<<"SCLL after insertion at position 3\n";
       DisplayWithLinks(head);
    /////////////////////////////////////
    /// inserting at the last of SCLL ///
    // Node *newNode = new Node;
    // newNode->data = 30;
    // Node *Last = GiveLastNode(head);
    // Last->next = newNode;
    // newNode->next = head;
    // DisplayWithLinks(head);
    /////////////////////////////////////

    /// deleting at the beginning ///
    // Node *t=head;
    // Node *last=GiveLastNode(head);
    // last->next=t->next;
    // head=t->next;
    // delete t;
    // DisplayWithLinks(head);
    ////////////////////////////////

    /// deleting at the last of node ///
    // Node *p=head;
    // do{
    //     p=p->next;
    // }while(p->next->next!=head);
    // delete p->next;
    // p->next=head;
    // DisplayWithLinks(head);
    ///////////////////////////////////

    /// deleting in b/w first and last node ///
    // Node *tem=head,*ptr=NULL;
    // int pos=3;
    // for(int i=0;i<pos-1;i++)
    // {
    //     ptr=tem;
    //     tem=tem->next;
    // }
    // ptr->next=tem->next;
    // delete tem;
    // DisplayWithLinks(head);

    /// reversing singly circular linked list ///
    head = ReverseLinks(head);
    cout<<"after reversing SCLL\n";
    DisplayWithLinks(head);
    return 0;
}

////////////// Doubt //////////////////
// Node* ReverseLinks(Node *p)//for SCLL
// {
//     Node *Prev=head;
//     Node *Current=head->next;//observe
//     Node *Next=head->next->next;
//     do{
//         Current->next=Prev;
//         Prev=Current;
//         Current=Next;
//         Next=Next->next;

//     }while(Current!=head->next);
//     return Current;
// }