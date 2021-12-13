#include<bits/stdc++.h>
using namespace std;
//similar to toposortbfs, just increment count in every iteration
//and at end check if count==n (DAG or not)
class Solution {
public:
	bool isCyclic(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
		//count indegree
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
		//All the elements with in degree 0 pushed in queue
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt = 0; //It counts the number of elements in the toposort
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        cnt++;  //Every element that was present in queue will be counted, (so if it is DAG then count=n at end)
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
        //If the count is greater than N ,this means that there is a cycle and toposort exists only for DAG 
	    if(cnt == N) return false; 
	    else return true; //yes cycle present so return true
	}
};



int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v); //directed graph so only one side
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}