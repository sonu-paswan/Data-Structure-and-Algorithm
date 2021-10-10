#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// stack using linked list
struct Node{
    int data;
    struct Node *next;
}*top=NULL;
//checking empty condition
int isEmpty(){
    return top==NULL;
}
void push(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    //algorithm to push an element in stack
    newNode->data=data;
    newNode->next=top;
    top=newNode;
}
int pop(){
    int x=INT_MIN;
    
    struct Node*temp=top;
    if(isEmpty()){
        printf("stack is empty");
        return x;
    }
    //algorithm pop an element from stack
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
    push(100);
    // Display();
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
}
//we can use infinty length stack using linked list

// note: - In stack using linked list the new element is  added  in the  head of linked list 
// and deletion is  also  done at head pointer 