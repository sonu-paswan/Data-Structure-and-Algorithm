

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        
       if(head==NULL){
           return -1;
       }
        Node * temp1=head;
        Node *temp2=head;
        while(temp2!=NULL&&temp2->next!=NULL){
            temp1=temp1->next;
            
            temp2=temp2->next->next;
        }
        return temp1->data;
    }
};


// { Driver Code Starts.

int main() {
    //code
    int t,j=1;
    cout<<"testcases :";
    cin>>t;
    while(t--){
        cout<<"number of elements for testcase "<<j++<<" :";
        int N;
        cin>>N;
        cout<<"enter data :";
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}
  // } Driver Code Ends