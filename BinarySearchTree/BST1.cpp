#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};
Node * NewNode(int data){
    Node *temp=new Node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node* insert(Node *root,int data){
    if(root==NULL){
        root=NewNode(data);
    }
    else{
        if(data>root->data){
            root->right=insert(root->right,data);
        }
        else{
            root->left=insert(root->left,data);
        }
    }
    return root;
}
bool search(Node *root,int key){
    if(root==NULL){
        return false;
    }
    else if(key==root->data){
        return true;
    }
    else{
        if(key>root->data){
            return search(root->right,key);
        }
        else{
            return search(root->left,key);
        }
    }
}
int main()
{
    int count,key;
    Node *root=NULL;
    cout<<"how many numbers :";
    cin>>count;
    cout<<"enter the numbers \n";
    for(int i=0;i<count;i++){
        int n;
        cin>>n;
        root=insert(root,n);
    }
    
    cout<<"enter a key for searching an element in BST :";
    cin>>key;
    search(root,key)?cout<<"true":cout<<"false";
}