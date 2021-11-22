#include <stdio.h>
#include <stdlib.h>
#include "treeADT.c"

// test program for tree ADT 

int main()
{
    struct tNode *root = NULL;
    printf("enter root :");
    int rootNum;
    scanf("%d",&rootNum);

    root = createNode(root, rootNum);
    root=createTree(root);

    printf("PreOrder traversal\n");
    PreOrderUsingStack(root);
    
    return 0;
}