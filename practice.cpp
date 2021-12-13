#include<bits/stdc++.h>
using namespace std;

void permutations(string str, int n, string result,map<string,int> & mp)
{
    if (n == 1)
    {
        mp[result+str]++;        
        return;
    }
 
    for (int i = 0; i < n; i++)
    {
        permutations(str.substr(1), n - 1, result + str[0],mp);
 
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

int main()
{
    string str;
    cin>>str;
    string ans=str;
    string result;
    sort(str.begin(),str.end());
    map<string,int> mp;
    permutations(str, str.size(), result,mp);
    int count=0;
    for(auto it: mp){
        count++;
        if(it.first==ans){
            cout<<count<<"\n"; break;
        }
    }
 
    return 0;
}