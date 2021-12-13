//Given a matirx of n*m where 0=sea 1=land
//return the no of land cells in grid for which we cannot walk off the boundary of grid

//So return the no of 1's which are not connected to end row/col

//Code is right, 2d vector input is creating problem same as countNoOfIslands
#include<bits/stdc++.h>
using namespace std;
//Similar to 06_countNoOfIslands
void findNoOfEnclaves(vector<vector<int>> adjList, int i, int j){
    if(i<0 || j<0 || i>=adjList.size() || j>=adjList[0].size() || adjList[i][j]==0 ){
        return;
    }
    
    adjList[i][j]=0;
    
    findNoOfEnclaves(adjList,i,j+1); //right
    findNoOfEnclaves(adjList,i,j-1);//left
    findNoOfEnclaves(adjList,i-1,j); //top
    findNoOfEnclaves(adjList,i+1,j); //down
}

int main(){
    int u,v;
    cin>>u>>v;
    vector<vector<int>> adjList;

    for(int i=0;i<u;i++){
        for(int j=0;j<v;j++){
            int temp;
            cin>>temp;
            adjList[i][j]=temp;
        }
    }

    // for(int i=0;i<u;i++){
    //     for(int j=0;j<v;j++){
    //         cout<<adjList[i][j]<<" ";
    //     }cout<<endl;
    // }

    for(int i=0;i<u;i++){
        for(int j=0;j<v;j++){
            if(i==0 || j==0 || i==u-1 || j==v-1){
                if(adjList[i][j]==1){ //if it is the last row or column and it is 1
                    //So with this only those elements with value 1 and connected to last col or row will be changed to 0
                    findNoOfEnclaves(adjList,i,j);
                    //Thus at the end only those 1 will remain in the matrix that arent connected to any end row/col
                    //Others will become 0
                }
            }
        }
    }
    int count=0;
     for(int i=0;i<u;i++){
        for(int j=0;j<v;j++){
            if(adjList[i][j]==1){
                count++;
            }
        }
    }
    cout<<count<<endl;


   return 0;
}