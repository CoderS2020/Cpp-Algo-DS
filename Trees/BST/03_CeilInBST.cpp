#include<bits/stdc++.h>
using namespace std;

//Ceil in BST: In BST find value >= val
//TC : Height of tree: O(log n)

struct TreeNode{
    int val;
    TreeNode * left,*right;
    TreeNode (int data){
        val=data;
        left=right=NULL;
    }
};

class Solution{
    public:
        int ceilInBST(TreeNode * root, int val){
            int ceil=-1;
            while(root!=NULL){
                if(root->val == val){
                    ceil=val; break;
                }
                else if(root->val < val){
                    root=root->right;
                }
                else{
                    ceil=root->val;
                    root=root->left;
                }
            }
            return ceil;
        }
};