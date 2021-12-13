/*
Make a new stack called support stack that stores the min element.

*/

#include<bits/stdc++.h>
using namespace std;
stack<int> s,ss;

void push(int a){
    s.push(a);
    if(ss.size()==0 || a<=ss.top()){
        ss.push(a);
    }
    return;
}

int pop(){
    if(s.size()==0) return -1;
    int ans=s.top();
    s.pop();
    if(ans==ss.top()){
        ss.pop();
    }
    return ans;
}

int getMin(){
    if(ss.size()==0) return -1;
    return ss.top();
}


int main(){


   return 0;
}