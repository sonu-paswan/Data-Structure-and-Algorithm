// queue using linked list in cpp

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
};
struct Queue{
    Node *front=NULL,*rear=NULL;
}*Q=NULL;
void enqueue(int data){
    Node *temp=new Node;
    temp->data=data;
    temp->next=NULL;
    if(Q==NULL){
        Queue *t=new Queue;
        t->front=temp;
        t->rear=temp;
        Q=t;
    }
    Q->rear->next=temp;
    Q->rear=temp;
}
int isEmpty(){
    if(Q->front==NULL && Q->rear==NULL)
    return 1;
    else return 0;
}
int dequeue(){
    int  x=-1;
    if(isEmpty()){
        cout<<"queue is empty\n";
    }
    else{
        x=Q->front->data;
        Q->front=Q->front->next;
    }
    return x;
}
int main()
{   
    enqueue(2);
    enqueue(4);
    enqueue(56);
    enqueue(27);
    enqueue(1);
    enqueue(8);
    enqueue(9);
    while(!isEmpty()){
        cout<<Q->front->data<<endl;
        dequeue();
    }
    return 0;
}