//BFS - Queue
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

/* Accepted Solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == NULL) return ans; 
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left != NULL) q.push(node->left); 
                if(node->right != NULL) q.push(node->right); 
                level.push_back(node->val); 
            }
            ans.push_back(level); 
        }
        return ans; 
    }
};
*/

void printLevelOrder(Node * root){
    if(root==NULL) return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL); // after each level is traversed we push NULL
    
    while(!q.empty()){
        Node * node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right); 
            }
        }
        else if(!q.empty()){ // if the element is null and queue is not yet empty
            q.push(NULL); // null is pushed in queue after every level change (dry run), bcz untill it reaches here all the next level elements are pushed in the queue and then we add Null here ie take careof next level
        }
    }
};



int sumAtk(Node * root,int k){
    if(root==NULL) return -1;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level=0,sum=0;

    while(!q.empty()){
        Node * node=q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}


int main(){

    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);


    // printLevelOrder(root);
    cout<<sumAtk(root,2);


   return 0;
}


