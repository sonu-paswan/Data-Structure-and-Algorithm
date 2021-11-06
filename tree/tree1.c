#include <stdio.h>
#include <stdlib.h>
#include "treeADT.c"

// test program for tree ADT 

int main()
{
    struct tNode *root = NULL;
    root = createNode(root, 4);
    root=createTree(root);
    printf("Level Order Traversal \n");
    printtree(root);
    printf("PreOrder traversal\n");
    PreOrder(root);
    printf("InOrder traversal\n");
    InOrder(root);
    printf("PostOrder traversal\n");
    PostOrder(root);
    return 0;
}