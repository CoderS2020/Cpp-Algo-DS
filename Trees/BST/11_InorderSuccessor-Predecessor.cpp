//Given a BST , find the immediate successor or predecessor of the given node
/*
Method 1: Inorder is sorted, so using binary search on this array we can find immediate next
or immediate previous element of that element.
TC- O(n)[for finding inorder] + O(log(n))[for finding element using BST]
SC- O(n)
*/

/*
Method 2: While finding inorder , when we find immediate predecessor/successor [immediate less or large value]
we return it.
TC- O(n)
SC-O(1)

*/

/*
Method 3: We know that elements to the left of node are smaller and on the right are greater.
So we can go to left or right and store immediate greater/smaller values.
TC-O(logn)
SC-O(1)
*/
/*
class Solution{
    public:
        TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p){
            TreeNode * successor=NULL;
            while(root!=NULL){
                if(p->val>=root->right){
                    root=root->right;
                }
                else{
                    successor=root;
                    root=root->left;
                }
            }
            return successor;
        }
}

class Solution{
    public:
        TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p){
            TreeNode * predecessor=NULL;
            while(root!=NULL){
                if(p->val<root->right){
                    root=root->left;
                }
                else{
                    predecessor=root;
                    root=root->right;
             
                }
            }
            return predecessor;
        }
}

*/