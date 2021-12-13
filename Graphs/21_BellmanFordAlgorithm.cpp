//Dijkstra doesnt work for negative cycles (but it detects the negative cycle)

//Time Complexity: O(n-1)*O(e)
//Space Complexity: O(n)

//Steps:
//1. Relax edges n-1 times i.e. if(dist[u]+wt < dist[v]){ dist[v]=dist[u]+wt}
//When you relax n-1 times -> the resulting array is the shortest dist possible
//If after doing it for n-1 times you again relax it and if this time it again decreases 
//then this means there exists a negative cycle

//When no weights use BFS, when positive weights use dijkstra, when nergative weight
//and negative cycle use bellman ford

//When you have to find shortest path from a source and edges can be negative
//then considering complexity (constraints) use bellman ford

#include<bits/stdc++.h>
using namespace std;
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

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); 

    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/