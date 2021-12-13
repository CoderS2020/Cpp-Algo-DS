//Construct BST from preorder traversal
//Preorder is given
//1st approach
//We know inorder of BST is sorted, so from preorder we can sort it to find inorder
//This question then becomes similar to finding tree when preorder and inorder are given.

//2nd approach
//We know that elements to the left of BST node are smaller and to the right are greater TC-O(3n) SC-O(1)

/*
class Solution{
    public:
        TreeNode * bstFromPreorder(vector<int> & preorder){
            int i=0;
            return build(preorder,i,INT_MAX);
        }
        TreeNode * build(vector<int> & preorder, int & i,int bound){
            if(i==preorder.size() || preorder[i]> bound) return NULL;
            TreeNode * root=new TreeNode(preorder[i++]); //Increasing i to move to next element
            root->left=build(preorder,i,root->val);
            root->right=build(preorder,i,bound);
            return root;
        }
        
}

*/