#include<bits/stdc++.h>
using namespace std;

const int n=86028121;
bool sieve[n+1];
vector<int> prime;

void createsieve(){
    for(int i=2;i<=n;i++){
        sieve[i]=true;
    }

    for(int i=2;i*i<=n;i++){
        if(sieve[i]==true){
            for(int j=i*i;j<=n;j=j+i){
                sieve[j]=false;
            }
        }        
    }

    for(int i=2;i<=n;i++){
        if(sieve[i]==true)
            prime.push_back(i);
    }

}

//1. Find the Kth Prime
int main(){
    createsieve();
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<prime[k-1]<<"\n";
    }

    return 0;
}

/*
Say they tell you to find 5*10^6th prime,
so till which number will you declare sieve array?

int limit=5*1000000;
int cnt=0;
int size=1;
for(int i=2;;i++){
    if(sieve[i]==true){
        cnt++;
    }
    if(cnt==limit){
        size=i;
        break;
    }
}
cout<<size;
*/