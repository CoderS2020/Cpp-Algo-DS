#include<bits/stdc++.h>
using namespace std;
//KMP Method
//Calculate the indices of the occurences of string s in t -> O(s+t)
//Abdul Bari YT - tushar roy code

vector<int> computePrefix(string pat){
    int m = pat.size();
    vector<int> longestPrefix(m);
    for(int i = 1, j = 0; i < m; i++){
        while(j > 0 && pat[j] != pat[i]){
            j = longestPrefix[j - 1];
        }
        if(pat[i] == pat[j]){
            longestPrefix[i] = ++j;
        }
        else{
            longestPrefix[i] = j; //j=0
        }
    }
    return longestPrefix;
}

void KMP(string str,string pat){
    int n = str.size();
    int m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
    for(int i = 0, j = 0; i < n; i++){
        while(j > 0 && pat[j] != str[i]){
            j = longestPrefix[j - 1];
        }
        if(str[i] == pat[j]){
            j++;
        }
        if(j == m){
            cout << i - m + 1 << "\n";
            j = longestPrefix[j - 1];
        }
    }
}


int main(){
   string s="swaraj";
   string t="Swaraj is swaraj and he is also called swaraj";
   KMP(t,s);

   return 0;
}


//--------
