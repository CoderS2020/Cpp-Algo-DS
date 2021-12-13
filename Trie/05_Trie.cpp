// GFG- Minimum XOR Value Pair
// Given an array of integers. Find pair in array that has min XOR value

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node * arr[26];
    bool flag=false;

    bool contains(char c){
        return (arr[c-'a']!=NULL);
    };

    void put(char ch,Node * newNode){
        arr[ch-'a']=newNode;
    };

    Node * getNext(char ch){
        return arr[ch-'a'];
    };
    void setFlag(){
        flag=true;
    };
    bool isFlagSet(){
        return flag;
    }
};

//Naive way- Run 2 for loops and find min xor for pair. TC- O(n^2)

//Optimized - The more MSB is to the left, the higher are chances to get lesser XOR
//Sort the array & take adjacent XOR's , then one of them will give you minimum XOR
/* //O(nlogn)
for(i=1;i<n;i++){
    minXor=min(minXor,a[i]^a[i-1]);
}
*/

//Optimized more-trie
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

int findminXor(int num){
    Node1 * temp=root1;
    for(int bit=31;bit>=0;bit--){
        int bitVal=num & (1<<bit);
        if(temp->contains(bitVal)){
            temp=temp->getNext(bitVal);
        }
        else if(temp->contains(!bitVal)){
            temp=temp->getNext(!bitVal);
        }
        else return INT_MAX;
    }
    return num ^ temp->value;
}

int findMinimumXOR(int a[],int n){
    int minXor=a[0] ^ a[1];
    insert(a[0]);
    for(int i=0;i<n;i++){
        minXor=min(minXor,findminXor(a[i]));
        insert(a[i]);
    }
    return minXor;
}

//For maximum Xor you have to check for different bits instead of same bits

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

//O(n*32)
int maximumXORSubarray(int arr[],int n){
    int prefixXor=arr[0];
    int maxXor=prefixXor;
    insert(prefixXor);
    for(int i=1;i<n;i++){
        prefixXor=prefixXor^arr[i];
        maxXor=max(maxXor,prefixXor);
        maxXor=max(maxXor,findmaxXor(prefixXor));
        insert(prefixXor);
    }
    return maxXor;
};