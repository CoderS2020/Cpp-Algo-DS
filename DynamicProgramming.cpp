#include<iostream>
using namespace std;
/*
int arr[1000]={0};
int fib(int n){
    if(arr[n]!=0) return arr[n];
    if(n==0 || n==1) return n;
    arr[n]= fib(n-1)+fib(n-2);
    return arr[n];
}*/
/*
long long int arr[100][100]={0};
long long int gridTraveller(int m,int n){
    
    if(arr[m][n]!=0) return arr[m][n];
    if(m==1 && n==1) return 1;
    if(m==0 || n==0) return 0;

    arr[m][n]=arr[n][m]= gridTraveller(m-1,n)+gridTraveller(m,n-1);
    return arr[m][n];
}
*/

int main(){
    // int n;
    // cin>>n;
    //Fibonnaci number using DP
    // cout<<fib(n);

    //gridTraveller 
    // int m,n; cin>>m>>n;
    // cout<<gridTraveller(m,n);

   return 0;
}