// use of stack in reversing linked list 

#include <iostream>
#include <stack>
using namespace std;
struct Node {
    int data ;
    Node * next;
};
Node *head=NULL;
void insert(int data){
    Node *temp=new Node;
    temp->data=data;
    temp->next=NULL;
    if (head==NULL){
        head=temp;
        return;
    }
    Node *temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}
void Print(){
    if(head==NULL){
        cout<<"list is empty\n";
        return;
    }
    Node *temp=head;
    while(temp!=NULL){
        printf("%d  %x  %x\n",temp->data,temp,temp->next);
        temp=temp->next;
    }
    cout<<endl;
}
void Reverse(){
    stack<Node*> S;
    if(head==NULL){
        cout<<"list is empty\n";
        return;
    }
    Node *temp=head;
    while(temp!=NULL){ // O(n)
        S.push(temp);
        temp=temp->next;
    }
    head=S.top();
    S.pop();
    Node *t=head;
    while(!S.empty()){ // O(n)
        Node *tem=S.top();
        S.pop();
        t->next=tem;
        t=tem;
    }
    t->next=NULL;
    // time complexity-> O(n)
    // space complexity-> O(n)
}
int main(){
    insert(2);
    insert(1);
    insert(5);
    insert(8);
    Print();
    Reverse();
    Print();
}
