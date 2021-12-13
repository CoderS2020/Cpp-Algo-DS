//Leetcode 1698

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

Node * root=new Node();
int distinctSubStrings(string s){
    Node * temp=root;
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(!temp->contains(s[j])){
                Node * newNode=new Node();
                temp->put(s[j],newNode);
                temp->setFlag();
                cnt++;
            }
            temp=temp->getNext(s[j]);
        }
    }
    return cnt;
};