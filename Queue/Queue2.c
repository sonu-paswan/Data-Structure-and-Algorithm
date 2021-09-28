#include <stdio.h>
#include <stdlib.h>
//queue implementation using array circular method
struct Queue
{
    int size;
    int front, rear;
    int *arr;
};
void CreateQueue(struct Queue *Q, int len)
{
    Q->size = len;
    Q->arr = (int *)malloc(sizeof(int) * Q->size);
    Q->rear = 0;
    Q->front = 0;
}
void enqueue(struct Queue *Q, int data)
{
    if ((Q->rear + 1) % Q->size == (Q->front) % Q->size)
    {
        printf("queue is full\n");
    }
    else
    {
        int rear = Q->rear = (Q->rear + 1) % Q->size;
        Q->arr[rear] = data;
    }
}
int dequeue(struct Queue *Q)
{
    int x = -1;
    if (Q->rear % Q->size == Q->front % Q->size)
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
void display(struct Queue *Q)
{
    if (Q->rear % Q->size == Q->front % Q->size)
    {
        printf("queue is empty\n");
    }
    else
    {
        int i = Q->front + 1;
        do
        {
            printf("%d ", Q->arr[i]);
            i = (i + 1) % Q->size;
        } while (i != (Q->rear+1) % Q->size);
        printf("\n");
    }
}
int main()
{
    struct Queue *queue=(struct Queue*)malloc(sizeof(struct Queue));
    CreateQueue(queue,5);
    enqueue(queue, 23);
    enqueue(queue, 30);
    enqueue(queue, 34);
    enqueue(queue, 90);
    enqueue(queue, 45);
    display(queue);
}