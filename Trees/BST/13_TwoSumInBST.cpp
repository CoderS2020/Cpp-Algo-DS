/*
Given a BST and k, check if in BST there exist exactly two nodes whose sum equals to k
1st Approach: Find inorder (which is sorted) and then using 2 pointers (start and end) find 2 values whose sum=k
Tc-O(n)+O(n)
SC-O(n)

2nd Approach: TC-O(n)
SC-O(h)*2
Here we make use of BST Iterator. We also find before(opposite of next) and doing opposite of next/hasNext process.
And then resonate with 2 sum problem process.

class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }


    bool hasNext() {
        return !myStack.empty();
    }


    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};
*/