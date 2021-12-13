#include<bits/stdc++.h>
using namespace std;

void func(int ind, vector<int> & ds, int arr[], int n){
    if(ind==n){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<"\n";
        return;
    }

    //include
    ds.push_back(arr[ind]);
    func(ind+1,ds,arr,n);

    ds.pop_back();
    
    //dont include
    func(ind+1,ds,arr,n);
    
}

void func(int ind, vector<int> & ds,int sum, int arr[], int n){
    if(ind==n){
        if(ds.size()!=0){
            for(auto it: ds){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        return;
    }

    //include
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    func(ind+1,ds,sum,arr,n);

    ds.pop_back();
    //dont include
    sum-=arr[ind];
    func(ind+1,ds,sum,arr,n);
    
}

int countF(int ind,int sum, int arr[], int n){
    if(sum==0) return 1;
    if(ind==n){
        if(sum==0) return 1;
        else return 0;
    }

    int left=0;
    int right=0;

    if(arr[ind]<=sum){
        sum-=arr[ind];
        left=countF(ind,sum,arr,n);
        sum+=arr[ind];
    }
    
    right=countF(ind+1,sum,arr,n);
    return left+right;
}

int n,m;
void findPaths(int i,int j,string s){

    if(i>=n || j>=m) return;

    if(i==n-1 && j==m-1){
        cout<<s<<endl;
        return ;
    }

    s+='D';
    findPaths(i+1,j,s);
    s.pop_back();

    s+='R';
    findPaths(i,j+1,s);
    s.pop_back();
}

string dir="DRUL";
int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};

void findPaths(int i, int j, string s, vector<vector<int>> & vis){

    if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1) return ; //vis to check if it comes back to same position

    if(i==n-1 && j==m-1){
        cout<<s<<endl;
        return ;
    }

    
    //Instead of writing all the conditions DRUL, we use an array and use for loop to traverse over it
    for(int x=0;x<4;x++){
        s+=dir[x];
        findPaths(i+di[x],j+dj[x],s,vis);
        s.pop_back();
    }
    vis[i][j]=0;

}

int findPaths(int i, int j,vector<vector<int>> & vis){

    // if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1 || a[i][j]==0) return 0; //a[i][j] means there is some hinderance in that path

    if(i==n-1 && j==m-1){
        return 1;
    }

    vis[i][j]=1;
    int cnt=0;

    for(int x=0;x<4;x++){
        cnt+=findPaths(i+di[x],j+dj[x],vis);
    }

    vis[i][j]=0;
    return cnt;

}

int arr[]={1,2,3,7,9,10,6};
int k=3;
bool func(int ind,vector<int> & ds, int sum){
    if(ind==n){
        if(sum%k==0){
            for(auto it:ds){
                cout<<it<<" ";
            }
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    sum+=arr[ind];
    if(func(ind+1,ds,sum)==true) return true;

    ds.pop_back();
    sum-=arr[ind];

    if(func(ind+1,ds,sum)==true) return true;
}


/*N-Queen*/

bool isSafe(int row,int col, vector<vector<int>> & mat){
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(mat[i][j]==1) return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;j--){
        if(mat[i][j]==1) return false;
    }
    for(int i=row,j=col;i<n && j>=0;i++,j--){
        if(mat[i][j]==1) return false;
    }
    return true;
}

bool NQueen(int col, vector<vector<int>> & mat){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,mat)){
            mat[row][col]=1;
            if(NQueen(col+1,mat)==true) return true;
            mat[row][col]=0;
        }
    }
    return false;
}

/*N Queen Optimized*/
bool isSafe2(int row,int col, vector<vector<int>> & mat, vector<int> & rowHash, vector<int> & thirdHash, vector<int> & firstHash){
   if(rowHash[row]==1 || thirdHash[row+col]==1 || firstHash[n-1+row-col]==1) return false;
    return true;
}

bool NQueen2(int col, vector<vector<int>> & mat, vector<int> & rowHash, vector<int> & thirdHash, vector<int> & firstHash){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    for(int row=0;row<n;row++){
        if(isSafe2(row, col, mat, rowHash, thirdHash, firstHash)){
            
            mat[row][col]=1;
            rowHash[row]=1;
            thirdHash[row+col]=1;
            firstHash[n-1+ row-col]=1;

            if(NQueen2(col+1,mat, rowHash, thirdHash, firstHash)==true) return true;
            mat[row][col]=0;            
            rowHash[row]=0;
            thirdHash[row+col]=0;
            firstHash[n-1+ row-col]=0;

        }
    }

    return false;
    
}