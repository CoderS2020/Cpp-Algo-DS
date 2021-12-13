#include<bits/stdc++.h>
using namespace std;

//Floor in BST: In BST find value <= val
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
        int floorInBST(TreeNode * root, int val){
            int floor=-1;
            while(root!=NULL){
                if(root->val== val){
                    floor=root->val;
                    break;
                }
                else if(root->val > val){
                    root=root->left;
                }
                else{
                    floor=root->val;
                    root=root->right;
                }
            }
            return floor;
        }
};

