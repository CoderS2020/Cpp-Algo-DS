#include<iostream>
using namespace std;

//Tiling problem
/*
int TilingWays(int n){

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return TilingWays(n-1) + TilingWays(n-2);
}


int main(){
    cout<<TilingWays(4);
    return 0 ;
}*/


//Friends pairing problem
/*int friendsPairing(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }

    return friendsPairing(n-1)+ friendsPairing(n-2)*(n-1);
}


int main(){
    cout<<friendsPairing(4)<<endl;
    return 0 ;
}*/

// 0-1 Knapsack Problem
// Put n items with given weight and value in a knapsack of capacity W to get the maximum total value in the knapsack
/*
int knapsack(int value[],int wt[],int n,int W){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(value,wt,n-1,W);
    }
 return max(knapsack(value,wt,n-1,W-wt[n-1])+value[n-1],knapsack(value,wt,n-1,W));

}

int main(){
    int wt[]={10,20,30};
    int value[]={100,50,150};
    int W=50;
    cout<<knapsack(value,wt,3,W);
    return 0;
}*/