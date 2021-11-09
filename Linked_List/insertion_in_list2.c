#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void setValue(struct Node *ptr)
{
    for (int i = 0; ptr != NULL; i++)
    {
        int value;
        scanf("%d", &value);
        ptr->data = value;
        ptr = ptr->next;
    }
}

void displayValue(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void insertList(struct Node **head, struct Node *ptr, int data, int position)
{
    ptr->data = data;
    if (position == 0)
    {

        ptr->next = *head;
        *head = ptr;
    }
    else
    {
        struct Node *temp = *head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
int MaxNum(struct Node * p)
{
    int max=INT_MIN;
    while(p)
    {
        if(p->data>max)
        max=p->data;
        p=p->next;
    }
    return max;
}

int main()
{
    struct Node *Head = NULL, *second = NULL, *third = NULL, *fourth = NULL;
    Head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    /////////// setting list ///////////
    Head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    ///////////////////////////////////
    printf("enter four values : ");
    setValue(Head);
    printf("display values : ");
    displayValue(Head);

    ////////////// insertion ////////////////

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    insertList(&Head, newNode, 45, 0);//insert after 3rd element
    printf("\nafter adding element at zeroth poistion\n");
    displayValue(Head);

    printf("\ngreatest number is list is %d",MaxNum(Head));

    //////////////////
   
    free(Head);
    
    return 0;
}
