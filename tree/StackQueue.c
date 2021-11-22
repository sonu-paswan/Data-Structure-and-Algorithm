/* basic function of queue for using it in tree  */
#include <stdlib.h>
#include <stdio.h>
#include "Tnode.c" // for tree structure

struct Queue
{
    int size;
    int front, rear;
    struct tNode **arr; // important 
};
int isFull(struct Queue *q)
{
    return (q->rear + 1) % q->size == (q->front) % q->size; // full condition
}
int isEmpty(struct Queue *q)
{
    return q->rear % q->size == q->front % q->size; // empty condition
}
void CreateQueue(struct Queue *Q, int len)
{
    Q->size = len;
    Q->arr = (struct tNode **)malloc(sizeof(struct tNode *) * Q->size);
    Q->rear = 0;
    Q->front = 0;
}
void enqueue(struct Queue *Q, struct tNode *t)
{
    if (isFull(Q))
    {
        printf("queue is full\n");
    }
    else
    {
        int rear = Q->rear = (Q->rear + 1) % Q->size;
        Q->arr[rear] = t;
    }
}
struct tNode *dequeue(struct Queue *Q)
{
    struct tNode *x = NULL;
    if (isEmpty(Q))
    {
        printf("queue is empty\n");
    }
    else
    {
        int front = Q->front = (Q->front + 1) % Q->size;
        x = Q->arr[front];
    }
    return x;
}
/* basic operations of stack for using in tree */

struct Stack
{
    int size;
    int top;
    struct tNode **array; // important
};
void CreateStack(struct Stack *S, int len)
{
    S->size = len;
    S->top = -1;
    S->array = (struct tNode **)malloc(sizeof(struct tNode *) * len);
}
int isEmptyinStack(struct Stack *S)
{
    return S->top == -1;
}
int isFullinStack(struct Stack *S)
{
    return S->top==S->size-1;
}
void push(struct Stack *S, struct tNode * t)
{
    if (isFullinStack(S))
    {
        printf("stack overflow\n");
        return;
    }
    S->top++;
    S->array[S->top] = t;
    // printf("%d is pushed\n", data);
}
struct tNode* pop(struct Stack *S)
{
    struct tNode *x = NULL;
    if (isEmptyinStack(S))
    {
        printf("stack underflow\n");
        return x;
    }
    x = S->array[S->top];
    S->top--;
    // printf("%d is poped\n", x);
    return x;
}