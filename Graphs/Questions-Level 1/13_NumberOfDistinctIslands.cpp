//Given a m*n matrix mat, return the number of distinct island
//An island is considered to be the same as another if and only if one island can be translated 
//( not rotated or reflected ) to equal the other.

#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<int>> &adj,string & psf, int m,int n,char ch){

    if(i<0 || j<0 ||i>=n || j>=m || adj[i][j]==0){
        return;
    }
    else{
            adj[i][j]=0;
            psf.push_back(ch);
            psf.push_back('b');
    }

    dfs(i-1,j,adj,psf,m,n,'t');
    dfs(i+1,j,adj,psf,m,n,'d');
    dfs(i,j+1,adj,psf,m,n,'r');
    dfs(i,j-1,adj,psf,m,n,'l');


}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    int val;
    //Remember this form of inputing vector of vector, because passing array as refrence is headache but vector of vector as a reference is not
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            cin>>val;
            temp.push_back(val);
        }
        adj.push_back(temp);
        temp.clear();
      
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<adj[i][j];
    //     }cout<<endl;
    // }
    string psf="";
    map<string,int> m1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(adj[i][j]==1){
                psf=""; //everything should be fresh
                
                dfs(i,j,adj,psf,m,n,'x');
                m1[psf]++;
            }
        }
    }

    // for(auto it1:m1){
    //     cout<<it1.first<<" "<<it1.second<<"\n";
    // }
    cout<<m1.size();
   return 0;

}