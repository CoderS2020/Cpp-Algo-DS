#include<bits/stdc++.h>
using namespace std;

//Greedily pick the minimum edge
//Check the complexities

struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){ 
	int N,m;
	cin >> N >> m;
	vector<node> edges; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    edges.push_back(node(u, v, wt)); 
	}
	//1. Sort edges wrt weight with the help of comp function
	sort(edges.begin(), edges.end(), comp); 
	
	//2. declare parent and rank vectors and findParent ,union
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; //parent is self
		
	vector<int> rank(N, 0); 
	
	//3. Traverse over the graph, if parents of vertices (of edges) are not same 
	//   then push to mst and also do union(since it is connected now)
	int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.u, parent) != findPar(it.v, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl; //Total weight of spanning tree
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}