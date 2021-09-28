// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};
// Structure to represent a stack
struct Stack
{
    int size;
    int top;
    int *arr;
};
void CreateStack(struct Stack *S, int len) //stack create
{
    S->size = len;
    S->top = -1;
    S->arr = (int *)malloc(sizeof(int) * len);
}
int Empty(struct Stack *S) //empty function for stack
{
    return S->top == -1;
}

// push function for stack
void push(struct Stack *S, int data)
{
    if (S->top >= S->size - 1)
    {
        printf("stack overflow\n");
        return;
    }
    S->top++;
    S->arr[S->top] = data;
    // printf("%d is pushed\n", data);
}
//pop function of stack
int pop(struct Stack *S)
{
    int x = INT_MIN;
    if (Empty(S))
    {
        printf("stack underflow\n");
        return x;
    }
    x = S->arr[S->top];
    S->top--;
    // printf("%d is poped\n", x);
    return x;
}
//function to create stack

// function to create a queue
struct Queue *create(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the append
    queue->rear = -1;
    queue->array = (int *)malloc(sizeof(int) * queue->capacity);
    return queue;
}

// Queue is full when size becomes

int isFull(struct Queue *Q)
{
    return (Q->size == Q->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue *Q)
{
    return (Q->size == 0);
}

// Function to add an item to the queue.

void append(struct Queue *Q, int item)
{
    if (isFull(Q))
        return;
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = item;
    Q->size = Q->size + 1;
    printf("%d appendd to queue\n", item);
}

// Function to Remove an item from queue.

int Remove(struct Queue *Q)
{
    if (isEmpty(Q))
        return INT_MIN;
    int item = Q->array[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->size = Q->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue *Q)
{
    if (isEmpty(Q))
        return INT_MIN;
    return Q->array[Q->front];
}

// Function to get rear of queue
int rear(struct Queue *Q)
{
    if (isEmpty(Q))
        return INT_MIN;
    return Q->array[Q->rear];
}
struct Queue *Reversequeue(struct Queue *Q, int len)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    CreateStack(stack, len);
    for (int i = 0; i < len; i++)
    {
        push(stack, Remove(Q));
    }
    struct Queue *newQ = create(len);
    for (int i = 0; i < len; i++)
    {
        append(newQ, pop(stack));
    }
    return newQ;
}
int main()
{
    int len = 5;
    struct Queue *queue = create(len);
    append(queue, 33);
    append(queue, 10);
    append(queue, 20);
    append(queue, 30);
    append(queue, 40);

    printf("Front element is %d\n", front(queue));
    printf("Rear element is %d\n", rear(queue));
    printf("another queue with reverse order of above queue\n");
    struct Queue *queue2 = Reversequeue(queue, len);

    // printf("%d is remove from queue\n", Remove(queue2));
    printf("Front element is %d\n", front(queue2));
    printf("Rear element is %d\n", rear(queue2));

    return 0;
}
