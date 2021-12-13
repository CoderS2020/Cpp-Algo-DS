// https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int

class triplet{
public:
	int first;
	int second;
	int third;
 
};
 
 
int n, m;	
vector<triplet> edges;
vector<int> dist;
vector<int> relaxant;
 
void bellman_ford()
{	
	int x;
	for(int i = 1; i <= n; ++i)  // n relaxations not n-1
	{
		x = -1;
		for(auto e: edges)
		{
 
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u]+d < dist[v])
			{
				dist[v] = d+dist[u];
				relaxant[v] = u; //stores previous vertex
				x = v;
			}
		}
	}
    //we have initialized x=-1 at start, so if it updated on nth iteration then 
    //it means negative cycle exists otherwise if it reamins -1 then no neg cycle
	if(x == -1) 
		cout << "NO" << endl;
 
	else
	{   //negative cycle exists
		for(int i = 1; i <= n; ++i)
		{
			x = relaxant[x]; //starting point of negative cycle*(dry run- there is always one)
		}
 
		vector<int> cycle;
 
		for(int v = x; ; v = relaxant[v])
		{
			cycle.push_back(v);
			if(v == x and cycle.size() > 1) //if it gets to the starting point ,then stop
				break;
		}
 
		reverse(cycle.begin(), cycle.end());
 
		cout << "YES" << endl;
		for(auto v: cycle)
		{
			cout << v << " ";
		}
 
		cout << endl;
	}
	
 
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	relaxant.resize(n+1);
	edges.resize(m);
	
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		edges[i] = inp;
	}
 
	for(int i = 1; i <= n; ++i)
	{
		relaxant[i] = -1;
	}
	bellman_ford();	
}