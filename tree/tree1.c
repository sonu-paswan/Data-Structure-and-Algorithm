#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
// struct tNode{                           //////////////////////
//     int data;                           //  this structure defination
//     struct tNode *Lchild;               //  is present in Tnode.c
//     struct tNode *Rchild;               ////////////////////
// };
void printtree(struct tNode *r)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    CreateQueue(q, 7);
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
            enqueue(q, temp->Lchild); // error
        }
        if (temp->Rchild)
        {
            enqueue(q, temp->Rchild); // error
        }
        temp = dequeue(q); // error
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
int main()
{
    struct tNode *root = NULL;
    root = createNode(root, 4);
    root->Lchild = createNode(root->Lchild, 7);
    root->Rchild = createNode(root->Rchild, 8);
    root->Lchild->Lchild = createNode(root->Lchild->Lchild, 6);
    root->Lchild->Rchild=createNode(root->Lchild->Rchild,10);
    root->Rchild->Rchild = createNode(root->Rchild->Rchild, 5);
    printtree(root);
    return 0;
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