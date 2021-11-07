#include <stdio.h>
#include <stdlib.h>
// sorting program for linked list 
struct Node
{
    int data;
    struct Node *next;
};
;
struct Node *create(struct Node *p) /* create function for linked list*/
{
    p = (struct Node *)malloc(sizeof(struct Node));
    printf("enter head data : ");
    int num;
    scanf("%d", &num);
    if (num == -1)
        return NULL;
    p->data = num;
    p->next = NULL;
    struct Node *last = p;
    int num2;
    while (1)
    {
        printf("enter data : ");
        getchar();
        scanf("%d", &num2);
        if (num2 == -1)
            break;
        else
        {
            struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
            NewNode->data = num2;
            NewNode->next = NULL;
            last->next = NewNode;
            last = NewNode;
        }
    }
    return p;
}
void DisPlay(struct Node *h)
{
    
    struct Node *temp = h;
    if(temp==NULL){
    printf("list is empty\n");
    return;
    }
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct Node *sort(struct Node *p) // selection sort for linked list
{
    if(p==NULL){
    printf("list is empty\n");
    return NULL;
    }
    struct Node *t1 = p;
    struct Node *t2 = NULL;
    while (t1->next)
    {
        t2 = t1->next;
        while (t2 != NULL)
        {
            if (t2->data < t1->data)
            {
                int temp = t2->data;
                t2->data = t1->data;
                t1->data = temp;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return p;
}
int main()
{
    struct Node *head = NULL;
    head = create(head);
    printf("Before Sorting \n");
    DisPlay(head);
    head = sort(head);
    printf("\nafter sorting\n");
    DisPlay(head);
    return 0;
}