#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 
//Steps:
//1. Find TopoSortDFS and store it in stack
//2. Make a new array / vector of size n that stores the shortest dist, newarray[source]=0, rest all elements are initialized to infinity
//3. Now traverse the stack and if newarray[st.top()]!=INF then traverse over the correspoding adjList and check if the current distance is less than the distance in newarray

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
	int vis[N] = {0};
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = INF;  //marked as infinity
	dist[src] = 0;  //mark source as 0

	//st has topoSort
	while(!st.empty()) 
	{  
		int node = st.top(); 
		st.pop(); 
	
		//If it is not infinity it means that the node has been reached previously
		if (dist[node] != INF) {
		    for(auto it : adj[node]) {
				//if the dist of source + dist of it is less than previous dist of it , then update
		        if(dist[node] + it.second < dist[it.first]) {
		            dist[it.first] = dist[node] + it.second; 
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) 
		(dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";  // INF means it is unreachable from soure
} 

int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; //directed graph
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 