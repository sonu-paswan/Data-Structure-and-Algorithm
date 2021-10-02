#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// stack using linked list
struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=top;
    top=newNode;
}
int pop(){
    int x=INT_MIN;
    
    struct Node*temp=top;
    if(temp==NULL){
        printf("stack is empty");
        return x;
    }
    top=top->next;
    x=temp->data;
    free(temp);
    return x;
}
void Display(){
    struct Node*temp=top;
    while(temp){
        printf("data =%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    push(34);
    push(3);
    push(53);
    push(98);
    // Display();
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
}