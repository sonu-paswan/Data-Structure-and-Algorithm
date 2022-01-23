#include <stdio.h>
#include <stdlib.h>
#include "StackQueue.c"
// struct tNode{                           //////////////////////
//     int data;                           //  this structure defination
//     struct tNode *Lchild;               //  is present in Tnode.c
//     struct tNode *Rchild;               ////////////////////
// };
void printtree(struct tNode *r) /* level order traversal in a tree */
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    CreateQueue(q, 50);
    struct tNode *temp = r;
    if (temp == NULL)
    {
        printf("tree  is empty\n");
        return;
    }
    while (temp)
    {
        printf("data : %d \n", temp->data);
        if (temp->Lchild)
        {
            enqueue(q, temp->Lchild);
        }
        if (temp->Rchild)
        {
            enqueue(q, temp->Rchild);
        }
        temp = dequeue(q);
    }
}
struct tNode *createNode(struct tNode *p, int data)
{
    p = (struct tNode *)malloc(sizeof(struct tNode));
    p->data = data;
    p->Lchild = NULL;
    p->Rchild = NULL;
    return p;
}
struct tNode *createTree(struct tNode *r) /* tree create function */
{
    int a, b;
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    struct tNode *temp = NULL, *p = NULL;
    CreateQueue(q, 50);
    enqueue(q, r);
    while (!isEmpty(q))
    {
        p = dequeue(q);
        printf("enter Left child of %d : ", p->data);
        scanf("%d", &a);
        if (a != -1)
        {
            temp = createNode(temp, a);
            p->Lchild = temp;
            enqueue(q, temp);
        }
        printf("enter right child of %d : ", p->data);
        scanf("%d", &b);
        if (b != -1)
        {
            temp = createNode(temp, b);
            p->Rchild = temp;
            enqueue(q, temp);
        }
    }
    return r;
}
void PreOrder(struct tNode *r) // Root Left Right
{
    if (r != NULL)
    {
        printf("data : %d\n", r->data);
        PreOrder(r->Lchild);
        PreOrder(r->Rchild);
    }
}
void InOrder(struct tNode *r) // Left Root Right
{
    if (r != NULL)
    {
        InOrder(r->Lchild);
        printf("data : %d\n", r->data);
        InOrder(r->Rchild);
    }
}
void PostOrder(struct tNode *r) // Left Right Root 
{
    if (r != NULL)
    {
        PostOrder(r->Lchild);
        PostOrder(r->Rchild);
        printf("data : %d\n", r->data);
    }
}
void PreOrderUsingStack(struct tNode *t)
{
    struct Stack *S=(struct Stack*)malloc(sizeof(struct Stack));
    CreateStack(S,50);
    while(1){
        while(t!=NULL){
            printf("%d ",t->data); // first process root 
            push(S,t); // then add to stack
            t=t->Lchild; // move to left sub tree
            
        }
        if(isEmptyinStack(S)){
            break;
        }
        t=pop(S);
        // after completing left sub trees go to right sub trees
        t=t->Rchild;
        
    }
}
void InOrderUsingStack(struct tNode *t)
{
    struct Stack *S=(struct Stack*)malloc(sizeof(struct Stack));
    CreateStack(S,50);
    while(1){
        while(t!=NULL){ 
            push(S,t); // first push left sub trees
            t=t->Lchild;
            
        }
        if(isEmptyinStack(S)){
            break;
        }
        t=pop(S);
        printf("%d ",t->data); // process the tree just aftere poping
        // after completing left sub trees go to right sub trees
        t=t->Rchild;
        
    }
}

/* level order traversal in tree algorithm (BFS: - breadth first search)
   1) Create an empty queue q
   2) temp_node = root / start from root /
   3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children
      (first left then right children) to q
    c) Dequeue a node from q.
*/