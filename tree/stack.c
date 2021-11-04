/* basic operations of stack for using in tree */

#include<limits.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
void CreateStack(struct Stack *S, int len)
{
    S->size = len;
    S->top = -1;
    S->arr = (int *)malloc(sizeof(int) * len);
}
int isEmpty(struct Stack *S)
{
    return S->top == -1;
}
void push(struct Stack *S, int data)
{
    if (S->top >= S->size - 1)
    {
        printf("stack overflow\n");
        return;
    }
    S->top++;
    S->arr[S->top] = data;
    printf("%d is pushed\n", data);
}
int pop(struct Stack *S)
{
    int x = INT_MIN;
    if (isEmpty(S))
    {
        printf("stack underflow\n");
        return x;
    }
    x = S->arr[S->top];
    S->top--;
    printf("%d is poped\n", x);
    return x;
}