#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v,int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }

    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return;
}

void sortRecursion(vector<int> & v){
    if(v.size()==1){
        return ;
    }

    int temp=v[v.size()-1];
    v.pop_back();
    sortRecursion(v);

    insert(v,temp);
    return;
}

int main(){
    vector <int> arr={4,1,5,2};
    sortRecursion(arr);
    for(auto i=arr.begin();i!=arr.end();i++){
        cout<<*i<<" ";
    }
   return 0;
}