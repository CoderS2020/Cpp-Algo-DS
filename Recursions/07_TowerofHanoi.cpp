#include<bits/stdc++.h>
using namespace std;

void solve(int s,int d,int h,int n){
    if(n==1){
        cout<<"Moving plate from "<<s<<" to "<<d;
        return;
    }
    solve(s,h,d,n-1);
    cout<<"Moving plate from "<<s<<" to "<<d;
    solve(h,d,s,n-1);
    return;


}


int main(){
    



   return 0;
}