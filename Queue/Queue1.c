#include <stdio.h>
#include <stdlib.h>
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
    Q->rear = -1;
    Q->front = -1;
}
void enqueue(struct Queue *Q, int data)
{
    if (Q->rear == Q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        int rear=Q->rear++;
        Q->arr[rear] = data;
    }
}
int dequeue(struct Queue *Q)
{
    int n = -1;
    if (Q->front == Q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int front=Q->front++;
        n = Q->arr[front];
        Q->arr[front]=0;
    }
    return n;
}
void Display(struct Queue *Q)
{
    if (Q->front == Q->rear)
        printf("Queue is Empty\n");
    else
    {
        int i = 0;
        for (i = Q->front + 1; i <= Q->rear; i++)
        {
            printf("%d ", Q->arr[i]);
        }
        printf("\n");
    }
}
// void fullDisplay(struct Queue *p){
//     for(int i=0;i<=p->rear;i++){
//         printf("%d ",p->arr[i]);
//     }
//     printf("\n");
// }
int main()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    CreateQueue(queue, 10);
    enqueue(queue, 34);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 340);
    Display(queue);
    printf("deleted element is %d\n",dequeue(queue));
    Display(queue);
    
    return 0;
}