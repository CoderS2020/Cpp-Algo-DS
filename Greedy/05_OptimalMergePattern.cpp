#include<bits/stdc++.h>
using namespace std;

/*
You are given n files with their computation times in an array. Choose any two files, add their computation
times and append it to the list of computation times. (Cost=Sum of computation time). Do this untill
we are left with only one file in the array. We have to do this operation such that we get minimum cost finally.
*/

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    priority_queue<int,vector<int> ,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    int ans=0;
    while(pq.size()>1){ //do untill only one file is left in the priority queue(see question)
        int e1=pq.top();
        pq.pop();
        int e2=pq.top();
        pq.pop();

        ans+=e1+e2;
        pq.push(e1+e2);
    }
    cout<<ans<<endl;


   return 0;
}