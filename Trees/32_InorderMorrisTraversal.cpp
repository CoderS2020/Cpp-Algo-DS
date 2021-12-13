//Threaded Binary Tree
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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder; 
        
        TreeNode* cur = root; 
        while(cur != NULL) {
            if(cur->left == NULL) { //if curr->left does not exist go to right
                inorder.push_back(cur->val); 
                cur = cur->right; 
            }
            else { //else go to curr->left and then go to right most end
                TreeNode* prev = cur->left; 
                while(prev->right != NULL && prev->right != cur) {
                    prev = prev->right; 
                }
                
                if(prev->right == NULL) {
                    prev->right = cur; //make connection of right most node with curr
                    cur = cur->left;  // go to curr's left
                }
                else {
                    prev->right = NULL; 
                    inorder.push_back(cur->val);  //add CURR value
                    cur = cur->right; //left is done , now move towards right
                }
            }
        }
        return inorder; 
    }
};


/*

*/