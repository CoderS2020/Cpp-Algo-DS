/*
BST Iterator: Traverse over inorder of given BST.
1st Approach: Store inorder of BST in a vector, TC -O(1) , SC-O(n)
2nd Approach: SC-O(h) , tc-O(1) per call (N elements for n calls n/n=1)
Go to all the lefts and then once it is removed from stack then go to all its right if there exist any and repeat 
the process
*/

/*
class BSTIterator {
private: stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode* root) {
         pushAll(root);
    }
    
     bool hasNext(){
            return !myStack.empty();
    }

    int next(){
        TreeNode * tmpNode=myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }
private:
        void pushAll(TreeNode * node){
            for(;node!=NULL;myStack.push(node),node=node->left);
        }
};

*/