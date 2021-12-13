/*
Individually solve each row, whenever you encounter 1 , put sum of above 1's in array
and whenever you encounter 0 , put 0 in array
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<int> v;
    for(int j=0;j<m;j++){
        v.push_back(arr[0][j]);
    }
    int mx=MAH(v); //MAH-> max area of histogram(prev problem)

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0) v[j]=0;
            else v[j]=v[j]+arr[i][j];
        }
        mx=max(mx,MAH(v)); //MAH-> max area of histogram(prev problem)
    }
    cout<<mx<<endl;
    

   return 0;
}