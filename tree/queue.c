/* basic function of queue for using it in tree  */
#include "Tnode.c" // for tree structure

struct Queue
{
    int size;
    int front, rear;
    struct tNode **arr;
};
int isFull(struct Queue *q)
{
    return (q->rear + 1) % q->size == (q->front) % q->size;
}
int isEmpty(struct Queue *q)
{
    return q->rear % q->size == q->front % q->size;
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
