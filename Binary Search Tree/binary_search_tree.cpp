#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node * insertBST(Node * root,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
};

void inorder(Node * root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
};

//Search in node
Node * searchNode(Node * root,int key){ //O(logn)
    if(root==NULL){
        return NULL;
    }
    
    if(root->data==key){
        return root;
    }
    else if(root->data>key){
       return searchNode(root->left,key);
    }
    else{
        return searchNode(root->right,key);
    }
};

//Delete in a node
//Case1: Node is a leaf
//Case2: Node has one child (here replace node with child and delete the node)
//Case3: Node has two children (find inorder successor-> replace inorder successor with node->node then comes in first or second case->delete the node )

//Find the inorder Successor (the leftmost element in right of root because that comes first)
Node * inorderSuccessor(Node * root){
    Node * curr=root;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}


Node * deleteinBST(Node * root,int key){
    
    if(key<root->data){
        root->left=deleteinBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteinBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node * temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            Node * temp=root->left;
            free(root);
            return temp;
        }
        //case 3
        Node * temp=inorderSuccessor(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data); //as we have made root as inorder successor then now we delete that inorder successor

    }
    return root;
};

//Build BST from preorder sequence
Node * constructBST(int preorder[],int *preOrderIdx,int key,int min,int max,int n){
    if(*preOrderIdx>=n){
        return NULL;
    }

    Node * root=NULL;
    if(key>min && key<max){
        root=new Node(key);
        *preOrderIdx=*preOrderIdx+1;

        if(*preOrderIdx<n){
            root->left=constructBST(preorder,preOrderIdx,preorder[*preOrderIdx],min,key,n);
        }
        if(*preOrderIdx<n){
            root->right=constructBST(preorder,preOrderIdx,preorder[*preOrderIdx],key,max,n);
        }
    }

    return root;
};



void printPreorder(Node * root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

//check for BST
bool isBST(Node * root,Node * min,Node * max){
    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftValid=isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);
    return (leftValid && rightValid);
}

//Sorted array to BST
//Strategy : Similar to Binary Search Algorithm

Node * buildBSTfromSorted(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node * root=new Node(arr[mid]);
    root->left=buildBSTfromSorted(arr,start,mid-1);
    root->right=buildBSTfromSorted(arr,mid+1,end);

    return root;


}

//Catalan Numbers: Sequence of natural numbers that occur in various counting problems, often
//involving recursivel defined objects




int main(){
    //Search in BST
    Node * root=NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    // inorder(root);

    // /Search Node
    // if(searchNode(root,4)==NULL){
    //     cout<<"Key doesnt exist";
    // }
    // else{
    //     cout<<"Key exists";
    // }

    //Delete BST
    // inorder(root);
    // cout<<endl;
    // deleteinBST(root,2);
    // inorder(root);

    //BST from preorder
    // int preorder[]={10,2,1,13,11};
    // int n=5;
    // int preorderIdx=0;
    // Node * root1=constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    // printPreorder(root1);

    //check if valid BST or not
    // Node * root1=new Node(10);
    // root1->left=new Node(5);
    // root1->right=new Node(22);


    // if(isBST(root1,NULL,NULL)){
    //     cout<<"Valid BST";
    // }
    // else{
    //     cout<<"Invalid BST";
    // }

    //Build tree from sorted array
    int arr[]={10,20,30,40,50};
    Node * root2= buildBSTfromSorted(arr,0,4);
    printPreorder(root2);



    return 0;
}

