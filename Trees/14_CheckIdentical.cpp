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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p) return !q; //returns true if both are null
        if(!q) return !p;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

