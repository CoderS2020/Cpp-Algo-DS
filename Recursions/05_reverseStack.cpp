#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }

    int val=s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    return;


}

void reverseStack(stack<int> &s){
    if(s.size()==1){
        return ;
    }

    int temp=s.top();
    s.pop();
    reverseStack(s);
    insert(s,temp);
    return;
}

void printStack(stack<int> s){
    if(s.empty()){
        return;
    }

    int temp=s.top();
    s.pop();
    printStack(s);
    cout<<temp<<" ";
    s.push(temp);
    return;
}




//Reverse a stack using recursion
int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);
    printStack(s);
   return 0;
}