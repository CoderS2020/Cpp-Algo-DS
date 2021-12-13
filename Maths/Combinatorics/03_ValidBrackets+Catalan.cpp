/*
Count the no of valid bracket sequences.
Valid bracket sequence definition:
a) Empty string is a valid bracket sequence
b) If S is a bracket sequence, so is (S)
c) If S,T are bracket sequences, then so is ST.

Solution
To check if it is valid bracket sequence:
At any point, the no of opening brackets should be greater than or equal to closing brackets otherwise return none
At end check if opening == closing


Think recursively
An=An-1 * A0 +An-2 *A1 + An-3*A2+ ... +A0*An-1
So for total possible sequences we calculate for all
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int MAXN=1000;
ll ans[MAXN];
ll mod=1e9+7; //to avoid overflow take mod

/* Method 1
int main(){

    ans[0]=1;
    for(int i=1;i<=MAXN;i++){
        for(int j=0;j<=i-1;j++){
            ans[i]+=ans[j]*ans[i-1-j] % mod;
        }
    }

    return 0;
}*/

/*
//Method 2
// Return all possible sequences

vector<string> generate(int n){
    if(n==0){
        return {""};
    }
    vector<string> completesequence;
    for(int i=0;i<=n-1;i++){
        vector<string> inside_bracket=generate(i);
        vector<string> outside_bracket=generate(n-1-i);
        for(string a : inside_bracket){
            for(string b: outside_bracket){
                string concatenated_string="("+a+")"+b;
                completesequence.push_back(concatenated_string);
            }
        }


    }
    return completesequence;
}

*/

//Method 3 : - Catalan Numbers
//An = good path - bad path
//An=(2*n)Cn - (2*n)Cn-1 = 2nCn/n+1
