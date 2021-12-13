#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    struct TreeNode* left,*right;
    int val;
    TreeNode(int data){
        val=data;
        left=NULL,right=NULL;
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN; 
        maxPathDown(root, maxi); //inspite of being int data type, just called not stored in any variable
        return maxi;  
    }
    //find left then right, then update maxi (maxsum), then return path
    int maxPathDown(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;
        //left has sum of elements to left, right has sum of elements to right
        int left = max(0, maxPathDown(node->left, maxi)); // if it is negative then make it 0
        int right = max(0, maxPathDown(node->right, maxi));
        maxi = max(maxi, left + right + node->val);//stores max answer
        return max(left, right) + node->val; //chooses either left/right and node(self) ie. path down
    }
};

