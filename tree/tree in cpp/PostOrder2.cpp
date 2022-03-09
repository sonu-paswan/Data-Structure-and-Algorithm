// iterative post order traversal in tree

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *right,*left;
};
Node * newNode(int data){
    Node* t=new Node;
    t->data=data;
    t->right=t->left=NULL;
    return t;
}
Node* createTree(){
    cout<<"enter root :";
    int t;
    cin>>t;
    Node *root=newNode(t);
    queue <Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<"enter left child of "<<temp->data<<" :";
        int left;
        cin>>left;
        if(left!=-1){
        Node *ltree=newNode(left);
        q.push(ltree);
        temp->left=ltree;
        }
        cout<<"enter right child of "<<temp->data<<" :";
        int right;
        cin>>right;
        if(right!=-1){
        Node *rtree=newNode(right);
        q.push(rtree);
        temp->right=rtree;
        }
    }
    return root;
}
void postorder(Node *root){
    stack<Node *> s;
    Node  *prev=NULL;
    do{
        while(root){
            s.push(root);
            root=root->left;
        }
        while(root==NULL&&!s.empty()){
            root=s.top();
            if(root->right==NULL || root->right==prev){
                s.pop();
                cout<<root->data<<" ";
                prev=root;
                root=NULL;
            }
            else
            root=root->right;
        }
    }while(!s.empty());
}
// time function :- T(n)=T(k) + T(n-k-1) + c
                //  where k is number of nodes in one side of a tree 
                // and n-k-1 another side of tree 
// time complexity -> O(n)
// space complexity -> O(h) h-height


int main()
{   Node *root=createTree();
    postorder(root);
    return 0;
}