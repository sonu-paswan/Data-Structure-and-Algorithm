#include <iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};
int height(Node *root){
    int lheight,rheight;
    
    if(root==NULL){
        return 0;
    }
    else{
        lheight=height(root->left);
        rheight=height(root->right);
    }
    return lheight>rheight?(lheight+1):(rheight+1);
    
}
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
int main()
{   Node *root=createTree();
    cout<<"height of a tree "<<height(root);
    return 0;
}