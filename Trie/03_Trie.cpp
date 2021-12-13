//Leetcode 1858 
/*
Given an array of string words, find the longest string in words such that every prefix of it also in words.
If there is more than one string with the same length , return lexicographically smallest one, if no string exists, return ""
*/


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


Node * root= new Node();
int insert(string word){
    Node * temp=root;
    int cnt=0;
    for(int i=0;i<word.size();i++){
        if(!temp->contains(word[i])){
            Node * newNode=new Node();
            temp->put(word[i],newNode);
        }
        if(temp->isFlagSet()) cnt++;
        temp=temp->getNext(word[i]);
    }
    temp->setFlag();
    return cnt;

};

string longestWord(vector<string> & words){
    sort(words.begin(),words.end());
    string res="";

    for(int i=0;i<words.size();i++){
        int cnt=insert(words[i]);        
        if(cnt==words[i].size()-1 && words[i].size()>res.size()){
            res=words[i];
        }
    }
    return res;
}

int main(){


   return 0;
}