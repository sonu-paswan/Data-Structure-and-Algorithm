//  program to multiply two matrix using linked list 
// application of linked list
// 30/10/2021
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
struct Node* MultiplyPoly(struct Node *A,struct Node *B, struct Node *C){
    struct Node*ptr1=B,*ptr2=C;
    while(ptr1!=NULL){
        ptr2=C;
        while(ptr2!=NULL){
            A=insertPoly(A,ptr2->data * ptr1->data,ptr1->expo + ptr2->expo);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return A;
}
int main(){
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    struct Node *head3=NULL;
    printf("enter for polynomial 1 \n");
    head1=create(head1);
    printf("enter for polynomial 2 \n");
    head2=create(head2);
    printf("after multiplication :\n");
    head3=MultiplyPoly(head3,head1,head2);
    printPoly(head3);
    return 0;
}
