#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;

    Node(int val){ 
        data=val;
        left=NULL;
        right=NULL;
    }

};

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr) return i;

    }
    return -1;
}

Node * buildTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;

    if(start>end){ //base condition
        return NULL;
    }

    int curr=preorder[idx];
    idx++;

    Node * node=new Node(curr); //make a new node from curr
    if(start==end) return node; //end condition
    int pos=search(inorder,start,end,curr); //search curr in inorder
    node->left=buildTree(preorder,inorder,start,pos-1); //build left subtree
    node->right=buildTree(preorder,inorder,pos+1,end); //build right subtree
    return node;
}

void inorderPrint(Node * root){
    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
    
}


int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    //build tree
    Node* root=buildTree(preorder,inorder,0,4);
    inorderPrint(root);


   return 0;
};

