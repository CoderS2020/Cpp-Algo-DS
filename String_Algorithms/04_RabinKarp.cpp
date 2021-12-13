//Calculate the indices of the occurences of string s in t O(s+t)
#include<bits/stdc++.h>
using namespace std;
//Abdul Bari YT 
//Avg Time Complexity: O(n-m+1)
//Worst Time Complexity: O(mn)


//apna college

int p=31;
const int N=1e5+7,m=1e9+7;
vector<long long> power(N);
int main(){
    string s="na";
    string t="apnacollegena";
    int T=t.size(),S=s.size();

    power[0]=1;
    for(int i=1;i<N;i++){
        power[i]=(power[i-1]*p)%m;
    }

    vector<long long> h(T+1,0);
    for(int i=0;i<T;i++){
        h[i+1]=(h[i]+(t[i]-'a'+1)*power[i])%m;
    }

    long long h_s=0;
    for(int i=0;i<S;i++){
        h_s=(h_s+(s[i]-'a'+1)*power[i])%m;
    }

    for(int i=0;i+S-1<T;i++){
        long long curr_h=(h[i+S]-h[i]+m)%m; //m is added to make sure it is always positive
        if(curr_h==h_s * power[i]%m){
            cout<<"Found at index "<<i<<endl;
        }
    }
   return 0;
}