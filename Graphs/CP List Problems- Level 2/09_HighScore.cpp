#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
const int INF = 1e17;
const int NINF = INF*(-1);
 
struct triplet{
	int first;
	int second;
	int third;
};
 
int n, m;	
vector<triplet> edges;
vector<int> dist;
 
void bellman_ford()
{
	for(int i = 1; i < n; ++i) //n-1 relaxations
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue; //bcz further lines will not execute anything,so we return and move to next edge
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
		}
	} 
 
	//we have finished n-1 relaxations , if relaxations are possible even after that ,
	//then it simply means there is a negative cycle. Then mark all the components of 
	//negative cycle as -INF
	for(int i = 1; i < n; ++i)
	{
		for(auto e: edges)
		{
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u] == INF) continue;
			dist[v] = max(dist[v], NINF);
			if(dist[u]+d < dist[v])
			{
				dist[v] = NINF;
			}
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	edges.resize(m);
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		inp.third *= -1; //reversing magnitude sign ( changing to finding minimum as opposed to question that asks to find max)
		edges[i] = inp;
	}
 
	for(int i = 2; i <= n; ++i)
	{
		dist[i] = INF;
	}
 
	bellman_ford();
	if(dist[n] == NINF)
	{
		cout << -1 << endl;
		return 0;
	} 
	cout << dist[n] * (-1) << endl; //we had taken -weight in input, so now we reverse magnitude
}