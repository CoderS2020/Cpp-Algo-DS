/*
String Hash: 
We convert strings into its unique hash which helps us in reducing complexity.
*/

#include<bits/stdc++.h>
using namespace std;
//Find no of unique strings
//Brute force approach
/*
int main(){
    vector<string> strings={"aa","ab","aa","b","cc","aa"};
    sort(strings.begin(),strings.end()); //O(nmlog(n)) m is length of string
    int distinct=0;           
    for(int i=0;i<strings.size();i++){
        if(i==0 || strings[i-1]!=strings[i]){
            distinct++;
        }
    }
    cout<<distinct<<endl;

   return 0;
}
*/

//Using Hashing- Sorting strings require extra m time for comparison, however comparing integers is done in O(1)time

int p=31;//there are 26 characters so take a number greater than 26 in this question
const int N=1e5+3,m=1e9+7;
vector<long long> powers(N);

long long calculate_hash(string s){
    long long hash=0;
    for(int i=0;i<s.size();i++){
        hash=(hash+(s[i]-'a'+1)*powers[i])%m;
    }
    return hash;
}

int main(){
    powers[0]=1;
    for(int i=1;i<N;i++){
        powers[i]=(powers[i-1]*p)%m;
    }
    vector<string> strings={"aa","ab","aa","b","cc","aa"};

    vector<long long> hashes;
    for(auto w:strings){
        hashes.push_back(calculate_hash(w)); //O(nm)
    }

    sort(hashes.begin(),hashes.end()); //O(nlog(n)) 
    int distinct=0;           
    for(int i=0;i<hashes.size();i++){
        if(i==0 || hashes[i-1]!=hashes[i]){
            distinct++;
        }
    }
    cout<<distinct<<endl;
    //Final : O(nm+nlogn)
    return 0;
}
