#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int data){
        val=data;
        left=right=NULL;
    }

};



class Solution {

public:
//st1 has preorder, but when st2 is filled, elements are ordered in postorder because of LIFO
//Very similar to iterative preorder (NULL is not passed)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1, st2; 
        st1.push(root); 
        while(!st1.empty()) {
            root = st1.top(); 
            st1.pop();
            st2.push(root); 
            if(root->left != NULL) { //left first
                st1.push(root->left); 
            }
            if(root->right != NULL) {
                st1.push(root->right); 
            }
        }
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val); 
            st2.pop(); 
        }
        return postorder;
    }
};


int main(){


   return 0;
}

