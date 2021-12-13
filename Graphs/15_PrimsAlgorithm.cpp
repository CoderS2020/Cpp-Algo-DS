#include<bits/stdc++.h>
using namespace std;

//Prims Algorithm: To find minimum spanning tree(n-1 edges with minimum weight), mst never has a cycle
//Checks out all the adjacent edges and chooses the minimum one

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false, parent[i]=-1; 
  

    key[0] = 0; //taking 0 as beginning
    // parent[0] = -1; 
    // int ansWeight = 0;
    for (int count = 0; count < N - 1; count++) //minimum spanning tree has n-1 edges
    { 
        
        int mini = INT_MAX, u; 
  
        //Find minimum vertex that is not included in mstSet
        for (int v = 0; v < N; v++) 
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
                
        mstSet[u] = true; //The selected minimum vertex is included in mstSet by marking it true
        
        // Traverse over all the adjacent edges
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])  //if it is not in mstSet and key[v] is greater than weight
                parent[v] = u, key[v] = weight;  //then update the parent and key
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}