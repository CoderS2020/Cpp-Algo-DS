//Calculate the indices of the occurences of string s in t
//string.substr(start position,size);
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="raj";
    string t="Swaraj raj rajkumar viraj";
    int S=s.size(),T=t.size();
    for(int i=0;i<=T-S;i++){ //O(T)
        if(t.substr(i,S)==s){//O(S)
            cout<<"Found at: "<<i<<endl;
        }
    }
    //Time Complexity: O(T*S)
    return 0;
}