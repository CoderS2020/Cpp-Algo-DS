#include<bits/stdc++.h>
using namespace std;



void insert(stack<int> &v, int temp){
    if(v.size()==0 || v.top()<=temp){
        v.push(temp);
        return;
    }

    int val=v.top();
    v.pop();
    insert(v,temp);
    v.push(val);
    return;
}

void sortStack(stack<int> &v){
    if(v.size()==1){
        return;
    }

    int temp=v.top();
    v.pop();
    sortStack(v);
    insert(v,temp);
    return;
}



void printStack(stack<int> v){
   if(v.empty()){
       return;
   }

   int x=v.top();
   v.pop();
   printStack(v);
   cout<<x;
   v.push(x);


}

int main(){

    stack <int> s;
    s.push(2);
    s.push(1);
    s.push(0);
    s.push(5);
   


    sortStack(s);

    printStack(s);


    return 0;
}