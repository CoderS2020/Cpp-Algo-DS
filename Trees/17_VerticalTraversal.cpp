#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int data){
        val=data;
        left=right=NULL;
    }

};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // (verticals, (level, nodes)) //multiset bcz it stores in ascending and also duplicate entries
        queue<pair<TreeNode*, pair<int, int>>> todo; //(node, <vertical,level>)
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end()); //muiltiset has ascending order but we want descending order
            }
            ans.push_back(col);
        }
        return ans;
    }
};


