// polynomial addition using linked list
// application of linked list
// 29/10/2021
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    int expo;
    struct Node *next;
};
struct Node *insertPoly(struct Node *, int, int);
struct Node *create(struct Node *ptr) // function to create polynomial
{
    int n, coef, exponent;
    printf("enter number of terms \n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("enter coefficient term %d :", i);
        scanf("%d", &coef);
        printf("enter exponent of term %d :", i);
        scanf("%d", &exponent);
        ptr = insertPoly(ptr, coef, exponent);
    }
    return ptr;
}
struct Node *insertPoly(struct Node *p, int coef, int exp) // insert function to store polynomial according to descending order
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = coef;
    newNode->expo = exp;
    newNode->next = NULL;
    if (p == NULL || exp >= p->expo)
    {
        if (p != NULL)
        {
            if (p->expo == exp)
            {
                p->data += coef; // for adding same expo coefficients
                return p;
            }
        }
        newNode->next = p;
        p = newNode;
    }
    else
    {
        struct Node *temp = p;
        while (temp->next != NULL && temp->next->expo >= exp)
        {
            if (temp->next->expo == exp)
            {
                int sum = temp->next->data + coef; // for adding same expo coefficients
                temp->next->data = sum;
                return p;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return p;
}
void printPoly(struct Node *ptr)
{
    struct Node *temp = ptr;
    if (temp == NULL)
    {
        printf("list is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%dx^%d", temp->data, temp->expo);
        if (temp->next)
        {
            printf(" + ");
        }
        else
            printf("\n");
        temp = temp->next;
    }
}
struct Node *AddPoly(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1, *ptr2 = head2; // using two pointers for traversal of linked list
    struct Node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo > ptr2->expo)
        {
            head3 = insertPoly(head3, ptr1->data, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            head3 = insertPoly(head3, ptr2->data, ptr2->expo);
            ptr2 = ptr2->next;
        }
        else  // for equal condition
        {
            head3 = insertPoly(head3, ptr1->data + ptr2->data, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL) // to add remaining elements of first polynomial
    {
        head3 = insertPoly(head3, ptr1->data, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) // to add remaining elements of second polynomial
    {
        head3 = insertPoly(head3, ptr2->data, ptr2->expo);
        ptr2 = ptr2->next;
    }
    return head3;
}
int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    head1 = create(head1);
    head2 = create(head2);
    head3 = AddPoly(head1, head2);
    printf("printing added polynomial\n");
    printPoly(head3);
    return 0;
}