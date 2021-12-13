#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node * left,*right;
    int data;
    Node(int val){
        data=val;
        left=NULL,right=NULL;
    }
};


class Solution {

public:
//stack not queue
//Go to extreme left, then push in inorder vector and then go to right
    vector<int> inorderTraversal(Node* root) {
        vector<int> inorder; 
        stack<Node*> st;  //we are not pushing root in this stack at the time of defining, we are doing it in the while loop
        Node* node = root;
        while(true) {
            if(node != NULL) {
                st.push(node); 
                node = node->left; 
            }
            else {
    
                if(st.empty() == true) break; 
                node = st.top(); //if it is null then redefine it to st.top() 
                st.pop(); 
                inorder.push_back(node->data); 
                node = node->right; 
            }  
        }
        return inorder; 
    }
};

int main(){


   return 0;
}

