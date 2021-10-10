#include <stdio.h>
#include <stdlib.h>
//gfg probelm solved for checking loop for linked list
struct Node{
    int data;
    struct Node*next;
}*head=NULL;
void createList(int a[],int  lenn){
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=a[0];
    head->next=NULL;
    struct Node*last=head;
    for(int i=1;i<lenn;i++){
        struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=a[i];
        newNode->next=NULL;
        last->next=newNode;
        last=newNode;
    }
}
void SetLoop(int pos){       // creating loop function
    struct Node *temp=head,*loop=head;
    if(pos==0){
        return;
    }
    else{
    while(temp->next!=NULL){
        temp=temp->next;
    }
    for(int i=0;i<pos-1;i++){
        loop=loop->next;
    }
    temp->next=loop;
    }
}
int detectLoop(struct Node* head) // loop checking program 
    {
        // your code here
        struct Node*temp1=head;
        struct Node*temp2=head;
        while(temp2!=NULL&&temp2->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next->next;
            if(temp1==temp2){
                return 1;
            }
        }
        return 0;
    }
int main()
{
    int arr[]={4,5,3,2,1,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    createList(arr,size);
    SetLoop(5);
    int result=detectLoop(head);
    if(result==1){
        printf("true\n");
    }
    else
    printf("false\n");
    return 0;
}