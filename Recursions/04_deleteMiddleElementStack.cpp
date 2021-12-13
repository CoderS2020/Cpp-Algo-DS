#include<bits/stdc++.h>
using namespace std;

//middleElement= (size/2)+1

void solve(stack<int> &s,int k){
    if(k==1){ //0 based indexing thats why we break at k=1
        s.pop();
        return;
    }

    int temp=s.top();
    s.pop();
    k--;
    solve(s,k);
    s.push(temp);
    return;
}

void deleteMidElemfromStack(stack <int> &s){
    if(s.size()==0){
        return ;
    }
    int k=(s.size()/2)+1;
    solve(s,k);
    return;
}

void printStackElem(stack<int> s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    printStackElem(s);
    cout<<temp<<" ";
    s.push(temp);
    return;
}

int main(){

    stack<int> s;
    s.push(1);
    s.push(14);
    s.push(7);
    s.push(4);
    s.push(10);

    deleteMidElemfromStack(s);
    printStackElem(s);


   return 0;
}



/*
https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1#
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int> & s,int k){
       if(k==1){ //0 based indexing thats why we break at k=1
        s.pop();
        return;
        }
    
        int temp=s.top();
        s.pop();
        solve(s,k-1);
        s.push(temp);
        return ;
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int k=(s.size()/2)+1;
        solve(s,k);
        
        
        
    }
};
*/