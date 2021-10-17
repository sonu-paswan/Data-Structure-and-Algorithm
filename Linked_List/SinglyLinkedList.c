#include <stdio.h>
#include <stdlib.h>
// Singly  Linked List in one Program 
// Menu Driven 
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
void createList(int A[], int size)//create function
{
    int i = 0;
    struct Node *last, *temp;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0]; //creating first node
    head->next = NULL;
    last = head;
    for (int i = 1; i < size; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void add(struct Node *ptr, int Data) //by default insert at last
{
    struct Node *temp = ptr;
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    last->data = Data;
    last->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = last;
}
void insertList(struct Node *p, int data, int position) //insert according to position
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (position == 0)
    {

        ptr->next = p;
        head = ptr;
    }
    else
    {
        struct Node *temp = p;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
int delete (struct Node *p, int pos) // delete by position
{
    int x = -1;
    if (head == NULL)
    {
        printf("list is empty!\n");
    }
    else
    {
        if (pos == 0)
        {
            struct Node *temp = p;
            x = temp->data;
            p = p->next;
            free(temp);
            head = p;
        }
        else
        {
            struct Node *t = p, *tem = NULL;
            for (int i = 0; i <= pos - 1; i++)
            {
                tem = t;
                t = t->next;
            }
            tem->next = t->next;
            int x = t->data;
            free(t);
        }
    }
    return x;
}
void displayValue(struct Node *p)
{
    if (p == NULL)
    {
        printf("list id empty!\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void displaywithlinks(struct Node *p) // display function
{
    if (p == NULL)
    {
        printf("list id empty!\n");
        return;
    }
    while (p)
    {
        printf("address=%4x  data =%4d  next=%4x\n", p, p->data, p->next);
        p = p->next;
    }
}
void menu()  
{
    printf("menu for linked list\n");

    printf("1) type a for add in linked list\n");
    printf("2) type i for insert in linked list\n");
    printf("3) type d for delete in linked list\n");
    printf("4) type D for Display linked list\n");
    printf("5) type E for exit\n");
}
int main()//  driver program
{
    int size;
    printf("enter size of linked list : \n");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    printf("enter elements of linked list ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    createList(arr, size);
    char choice = 'a';
    menu();
    while (choice != 'E')
    {
        printf("enter choice: ");
        getchar();
        scanf("%c", &choice);
        switch (choice)
        {
        case 'a':
            printf("enter element :");
            int data2;
            scanf("%d", &data2);
            add(head, data2);
            break;
        case 'i':
            printf("enter element and position\n");
            int data3, pos;
            scanf("%d %d", &data3, &pos);
            insertList(head, data3, pos);
            break;
        case 'd':
            printf("enter position for delete: \n");
            int pos2;
            scanf("%d", &pos2);
            delete (head, pos2);
            break;
        case 'D':
            displaywithlinks(head);
            break;
        default:
            printf("invalid input\n");
            break;
        }
    }
    return 0;
}