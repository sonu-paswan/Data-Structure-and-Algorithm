#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
;
void add(struct Node *ptr, int data)
{
    struct Node *temp = NULL;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (ptr == NULL)
    {
        head = newNode; //update head node
    }
    else
    {
        temp = ptr;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("data=%d  link=%x\n", p->data, p->next);
        p = p->next;
    }
    printf("\n");
}
void insert(struct Node *Head, int data)//insert function in ascending order
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (Head == NULL || data < head->data)//insertion at first if element is less than head->data
    {
        newNode->next = Head;
        head = newNode;
    }
    else
    {
        struct Node *temp = Head;
        while (temp->next != NULL && temp->next->data < data)//insertion after head node
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void polynomial(struct Node *Head){//incomplete function
}
int main()
{
    // add(head,390);
    insert(head, 38);
    insert(head, 34);
    insert(head, 4);
    insert(head, 76);
    insert(head, 3);
    display(head);

    return 0;
}