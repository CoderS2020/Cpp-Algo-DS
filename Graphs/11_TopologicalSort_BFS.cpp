#include<bits/stdc++.h>
using namespace std;

//Kahn's Algorithm: In degree method
class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q;
	    vector<int> indegree(N, 0);
        //Exception: Here we are not implementing regular BFS strategy of running it through loop at beginning 
        //i.e. for(int i=0;i<n;i++){if(!vis[i]){//bfs}}
        //Unless it is mentioned that you have to implement Topo using BFS , dont use BFS , stick to DFS
        // 1.Calculate indegree
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++;  //Calculating the indegree
	        }
	    }
	    
        //Push elements with indegree 0 in queue
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
        //Simple bfs : but decrease indegree by 1 everytime that element is calculated
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};


int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topo(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
} 