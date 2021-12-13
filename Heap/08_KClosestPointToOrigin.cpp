/*
Given 2 d array of (x,y) co-ordinates, find the k closest points to origin.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int v[4][2]={{1,3},{-2,2},{5,8},{0,1}};
    int k=2;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0;i<4;i++){
        pq.push({v[i][0]*v[i][0] + v[i][1]*v[i][1],{v[i][0],v[i][1]} });
        if(pq.size()>k)pq.pop();
    }

    while(!pq.empty()){
        pair<int,int> p=pq.top().second;
        cout<<p.first<<" "<<p.second<<endl;
        pq.pop();
    }


   return 0;
}