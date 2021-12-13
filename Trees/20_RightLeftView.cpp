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
    //right then left for right side view
    //left then right for left side view
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
