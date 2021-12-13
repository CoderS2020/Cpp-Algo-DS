//Shortest Path using BFS

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pr;
int n,x,y,x1,y1,r,a,b;
int dx[9]={-1,-1,-1,0,1,1,1,0},dy[9]={-1,0,1,1,1,0,-1,-1};
queue<pr>q;
map<pr,int>mp;//stores shortest dist from start point

int main(){
	scanf("%d%d%d%d%d",&x,&y,&x1,&y1,&n);
	while(n--){
		scanf("%d%d%d",&r,&a,&b);
		for(int i=a;i<=b;i++)
		mp[pr(r,i)]=-1; // segment allowed to travel
	}	
	mp[{x,y}]=0; //start is 0 (dist )
    mp[{x1,y1}]=-1; //end is -1(yet to be reached)
	q.push({x,y}); //push in queue (bfs)

	while(q.size()){
		pr u=q.front();
		q.pop();

		//Travel all the 8 sides, if it is already not visited , then store the dist(prevDist+1)
		for(int i=0;i<8;i++){
			pr v=pr(u.first+dx[i],u.second+dy[i]);
			if(mp[v]==-1)
			mp[v]=mp[u]+1,q.push(v);
		}
	}

	printf("%d",mp[{x1,y1}]);
	return 0;
}