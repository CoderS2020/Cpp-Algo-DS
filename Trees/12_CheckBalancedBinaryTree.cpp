//Balanced Binary Tree: For every node , height(left)-height(right)<=1

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

int height(Node * root){
    if(root==NULL) return 0;

    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;

}

//Balanced Binary Tree: for each node, the difference between the heights of the left subtree and right subtree <=1

bool isBalanced(Node * root){
    if(root==NULL) return true; //by default it is 0 i.e. balanced


    if(isBalanced(root->left)==false){
        return false;
    }
    
    if(isBalanced(root->right)==false){
        return false;
    }

    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }

}

//optimized isBalanced
bool isBal(Node * root, int * height){
    if(root==NULL) return true;


    int lh=0,rh=0;
    if(isBal(root->left,&lh)==false) return false;
    if(isBal(root->right,&rh)==false) return false;

    *height=max(lh,rh)+1;

    if(abs(lh-rh)<=1) return true;
    else return false;

}

int main(){

    Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    if(isBalanced(root)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }

    int height=0;
    if(isBal(root,&height)){
        cout<<"Balanced"<<endl;
        cout<<height<<" ";
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
   return 0;
}

