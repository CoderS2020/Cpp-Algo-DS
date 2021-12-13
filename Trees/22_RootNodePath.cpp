//Print path from root to node
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    TreeNode * left,*right;
    int val;
    TreeNode(int data){
        val=data;
        left=right=NULL;
    }
};

//using inorder traversal
bool getPath(TreeNode *root, vector<int> &arr, int x) {
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->val);   
     
    // if it is the required node
    // return true
    if (root->val == x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    arr.pop_back();
    return false;  
}
vector<int> solve(TreeNode* A, int B) {
    vector<int> arr; 
    if(A == NULL) {
        return arr; 
    }
    getPath(A, arr, B); //return type is bool
    return arr; 
}
