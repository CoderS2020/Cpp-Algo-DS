//Leetcode 1804

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node * arr[26];
    int cntWordsEnd=0;
    int cntPrefix=0;
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
    void incWordsEndWith(){
        cntWordsEnd++;
    };
    void incCntPrefix(){
        cntPrefix++;
    };
    void decWordsEndWith(){
        cntWordsEnd--;
    };
    void decCntPrefix(){
        cntPrefix--;
    };
    int getCountWordsEnd(){
        return cntWordsEnd;
    };

    int getCountPrefix(){
        return cntPrefix;
    };
    bool isFlagSet(){
        return flag;
    };
};

Node * root= new Node();
void insert(string word){
    Node * temp=root;
    for(int i=0;i<word.size();i++){
        if(!temp->contains(word[i])){
            Node * newNode=new Node();
            temp->put(word[i],newNode);
        }
        temp->incCntPrefix();
        temp=temp->getNext(word[i]);
    }
    temp->incWordsEndWith();
    temp->flag=true;

};

bool search(string word){
    Node * temp=root;
    for(int i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else{
            return false;
        }
    }
    return temp->isFlagSet();
};

int countsWordsEqualTo(string word){
    Node * temp=root;
    for(int i=0;i<word.size();i++){
        if(temp->contains(word[i])){
            temp=temp->getNext(word[i]);
        }
        else{
            return false;
        }
    }
    return temp->getCountWordsEnd();
};

int startsWith(string prefix){
    Node * temp=root;
    for(int i=0;i<prefix.size();i++){
        if(temp->contains(prefix[i])){
            temp=temp->getNext(prefix[i]);
        }
        else{
            return 0;
        }
    }
    return temp->getCountPrefix();
};

void erase(string word){
    Node * temp=root;
    if(search(word)==0) return ;
    for(int i=0;i<word.size();i++){ // not deleting the link as it is not required and it will get very complex
        temp->decCntPrefix();
        temp->getNext(word[i]);
    }
    temp->decWordsEndWith();
}

int main(){


   return 0;
}