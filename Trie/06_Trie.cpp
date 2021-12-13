//Leetcode 1707

/*
1.Sort queries
*/

#include<bits/stdc++.h>
using namespace std;

struct Node1{
    Node1 * arr[2]; //0,1
    int value;

    bool contains(int bitNo){
        return (arr[bitNo]!=NULL);
    };

    void put(int bitNo,Node1 * newNode){
        arr[bitNo]=newNode;
    };

    Node1 * getNext(int bitNo){
        return arr[bitNo];
    };

};

Node1 * root1=new Node1();

void insert(int num){
    Node1 * temp=root1;
    for(int bit=31;bit>=0;bit--){
        
        int bitVal=num & (1<<bit);
        if(temp->contains(bitVal)){
            temp=temp->getNext(bitVal);
        }
        else{
            temp->put(bitVal, new Node1());
            temp=temp->getNext(bitVal);
        }        
    }
    temp->value=num;
};

bool comp(vector<int> v1, vector<int> v2){
    if(v1[1]< v2[1]) return true;
    return false;
}


int findmaxXor(int num){
    Node1 * temp=root1;
    for(int bit=31;bit>=0;bit--){
        int bitVal=num & (1<<bit);
        if(temp->contains(!bitVal)){
            temp=temp->getNext(!bitVal);
        }
        else if(temp->contains(bitVal)){
            temp=temp->getNext(bitVal);
        }
        else return INT_MIN;
    }
    return num ^ temp->value;
}


vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> & queries){
    vector<vector<int>> query=queries;
    for(int i=0;i<queries.size();i++){
        query[i].push_back(i);
    }
    sort(nums.begin(),nums.end());
    sort(queries.begin(),queries.end(),comp);
    vector<int> ans(queries.size(),0);
    int i=0;
    for(auto it:query){
        int num=it[1];
        while(i<nums.size() && nums[i]<=num){
            insert(nums[i]);
            i++;
        }
        ans[it[2]]=findmaxXor(it[0]);
    }
    return ans;
};


int main(){


   return 0;
}
