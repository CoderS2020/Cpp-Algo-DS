/*
Kth smallest / largest element in BST.
Inorder is always sorted.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0; 
        int ans = -1; 
        TreeNode* cur = root; 
        while(cur != NULL) {
            if(cur->left == NULL) {
                cnt++; 
                if(cnt == k) ans = cur->val;  
                cur = cur->right; 
            }
            else {
                TreeNode* prev = cur->left; 
                while(prev->right != NULL && prev->right != cur) {
                    prev = prev->right; 
                }                
                if(prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left; 
                }
                else {
                    prev->right = NULL;            
                    cnt++; 
                    if(cnt == k) ans = cur->val;
                    cur = cur->right; 
                }
            }
        }
        return ans; 
    }
};

*/