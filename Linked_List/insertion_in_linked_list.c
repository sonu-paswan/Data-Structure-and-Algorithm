#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {

        printf("element [%d]=%d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
}
//insertion at the last
void Push_Back(struct Node *ptr,int Data)  //by default insert at last
{
    struct Node *temp=ptr;
    struct Node *last=(struct Node *)malloc(sizeof(struct Node));
    last->data=Data;
    last->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=last;
    last=temp;
}
int main()
{
    struct Node *head = NULL, *second = NULL, *third = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = second;
    second->data = 9;
    second->next = third;
    third->data = 8;
    third->next = NULL;

    printf("Before insertion\n");

    display(head);

    ///////////////////////// insertion at starting node ///////////////////////////
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));

    printf("After insertion at begining\n");
    first->data = 90;
    first->next = head;
    head = first;
    display(head);
    //////////////////////////  insertion at the last /////////////////////////////
    
    Push_Back(head,78);
    Push_Back(head,56);
    Push_Back(head,23);
    printf("new linked list after inertion at last\n");
    display(head);
    
    return 0;
}