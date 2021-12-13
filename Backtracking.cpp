#include<iostream>
using namespace std;

//Rat in a maze
/*
bool isSafe(int ** arr,int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratinMaze(int ** arr,int x,int y,int n,int ** solArr){

    if(x==n-1 && y==n-1){ //base condition
        solArr[x][y]=1;
        return true;
    }
    if(isSafe(arr,x,y,n)){
        solArr[x][y]=1;
        if(ratinMaze(arr,x+1,y,n,solArr)){
            return true;
        }
        if(ratinMaze(arr,x,y+1,n,solArr)){
            return true;
        }
        solArr[x][y]=0; //back tracking
        return false;
    }
    return false;
}

int main(){

    int n;
    cin>>n;
    int ** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int [n];
    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cin>>arr[i][j];
       }
    }

    
    int ** solArr=new int*[n];
    for(int i=0;i<n;i++){
        solArr[i]=new int [n];
        for(int j=0;j<n;j++){
            solArr[i][j]=0;
        }
    }
    cout<<endl;
    if(ratinMaze(arr,0,0,n,solArr)){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<solArr[i][j]<<" ";
        }cout<<endl;
    }
    }
    return 0;
}*/

//N-Queen Problem
/*
bool isSafe(int ** arr, int x, int y, int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    int row=x,col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    
    row=x,col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    
    return true;
}

bool nQueen(int ** arr, int x,int n){

    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;

            if(nQueen(arr,x+1,n)){
                return true;
            }

            arr[x][col]=0;  //backtracking
        }
    }
    return false;
}


int main(){

    int n;
    cin>>n;

    int ** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
       
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    }


    return 0;
}*/