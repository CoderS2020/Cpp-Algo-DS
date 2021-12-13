//BiPartite Graph : A Graph that can be colored using exactly two colors such that 
//no two adjacent nodes have same colors

// Any graph that has odd length cycle cannot be bipartite otherwise it is bipartite for all the rest cases.
//Using BFS
#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; //thus it will either be 0 or 1
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n]; //in place of vis we have color
    memset(color, -1, sizeof color); //initialize array 'color' with -1
    for(int i = 0;i<n;i++) { //0 based indexing: remember
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) {
	    cout << "Yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

