#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }

};


class Solution {

public:
    //Stack Used not queue
    vector<int> preorderTraversal(Node* root) {
        vector<int> preorder;
        if(root == NULL) return preorder; 
       
        stack<Node*> st; 
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop(); 
            preorder.push_back(root->data); 
            if(root->right != NULL){ //right first then left bcz LIFO
                st.push(root->right);
            }
            if(root->left!= NULL){
                st.push(root->left);
            }
        }
        return preorder; 
    }
};

int main(){
    struct Node * root=new Node(2);
   return 0;
}


