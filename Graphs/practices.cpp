#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int i1=INT_MAX,j1=INT_MAX;
        int land=0,water=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) water++;
                else land++;

                if(grid[i][j]==1){
                    if(i1==INT_MAX && j==INT_MAX){
                        i1=i,j1=j;
                        q.push({i1,j1});
                    }
                    grid[i][j]=-1;
                }
            }
        }

        if(land==grid.size() || water==grid.size()){
            return -1;
        }
        int maxDist=0;
        while(!q.empty()){
            int qsize=q.size();

            while(qsize--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i-1>=0){
                    if(grid[i-1][j]!=-1){
                        grid[i-1][j]=1+grid[i][j];                        
                        q.push({i-1,j});
                        maxDist=max(maxDist,1+grid[i][j]);
                    }
                }
                if(j-1>=0){
                    if(grid[i][j-1]!=-1){
                        grid[i][j-1]=1+grid[i][j];
                        q.push({i,j-1});
                        maxDist=max(maxDist,1+grid[i][j]);

                    }
                }
                if(i+1<grid.size()){
                    if(grid[i+1][j]!=-1){
                        grid[i+1][j]=1+grid[i][j];
                        q.push({i+1,j});
                        maxDist=max(maxDist,1+grid[i][j]);
                    }
                }
                if(j+1<grid[0].size()){
                    if(grid[i][j+1]!=-1){
                        grid[i][j+1]=1+grid[i][j];
                        q.push({i,j+1});
                        maxDist=max(maxDist,1+grid[i][j]);
                    }
                }
            }
        }

        return maxDist;


        
        
        

    }
};