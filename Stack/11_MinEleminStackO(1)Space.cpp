/*
Push
If element to be pushed is greater than minEle,then push the no as it is,else push 2*element - minEle and update minElem=element
*/

#include<bits/stdc++.h>
using namespace std;

int minEle;
stack<int> s;

int getMin(){
   if(s.size()==0) return -1;
   return minEle;
}

void push(int x){
   if(s.size()==0){
      s.push(x);
      minEle=x;
   }
   else{
      if(x>=minEle)s.push(x);
   }
   else if(x<minEle){
      s.push(2*x-minEle);
      minEle=x;
   }
}

void pop(){
   if(s.size()==0){
      return;
   }
   else{
      if(s.top()>=minEle){
         s.pop();
      }
      else if(s.top()<minEle){
         minEle=2*minEle-s.top();
         s.pop();
      }
   }
}

int top(){
   if(s.size()==0)return -1;
   else{
      if(s.top()>=minEle) return s.top();
      else if(s.top()<minEle) return minEle;
   }
}


int main(){


   return 0;
}