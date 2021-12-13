#include<bits/stdc++.h>
using namespace std;

//In worst case , search will be equal to height of tree ie. O(logn)

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
        TreeNode * searchBST(TreeNode * root,int val){
            while(root!=NULL && root->val!=val){
                root=val<root->val? root->left:root->right;
            }
            return root;
        }
};

