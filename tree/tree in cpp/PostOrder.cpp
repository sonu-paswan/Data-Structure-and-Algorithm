#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left,*right;
};
struct Node * newNode(int data){
    Node * newroot=new Node;
    newroot->data=data;
    newroot->left=NULL;
    newroot->right=NULL;
    return newroot;
}
vector<int> PostOrder(Node *head)
    {
        vector<int> v;
        if(head==NULL){
            return v;
        }
        stack <Node *> s;
        
        
        Node *root=head;
        do{
            while(root){
                if(root->right)
                s.push(root->right);
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(root->right && s.empty()?false:root->right==s.top()){
                s.pop();
                s.push(root);
                root=root->right;
            }
            else{
                v.push_back(root->data);
                root=NULL;
            }

        }while(!s.empty());
        return v;
    }

void PostOrderTraversal(Node *root){
    if(root!=NULL){
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout<<root->data<<" ";
    }

}
int main() {
    //code
    
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root->right->right->right=newNode(9);
    vector<int>::iterator i;
    vector<int> v;
    
    v=PostOrder(root);
    for(i=v.begin();i!=v.end();i++)
    cout<<*i<<" ";
    return 0;
}