#include<bits/stdc++.h>
using namespace std;

int main(){
    // set<int> s;
    //In a set elements are sorted and no duplicates allowd unlike multiset.

    // set<int,greater<int>> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(2);

    // for(auto i:s)
    //     cout<<i<<" ";
    // cout<<endl;
    // s.erase(1);
    // for(auto i=s.begin();i!=s.end();i++){
    //     cout<<*i<<" ";
    // }

    multiset<int> ms;
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);

    for(auto i:ms)
        cout<<i<<" ";
    cout<<endl;
    ms.erase(3); //it will erase all occurences of 3
    // if we want to remove only one occurence in a multiset

// Unordered set.: contains unique elements, not sorted. rest same as set
unordered_set<int> us;
us.insert(1);
us.insert(1);
us.insert(2);
us.insert(3);
us.erase(3);

for(auto i:us)
    cout<<i<<" ";


   return 0;
}