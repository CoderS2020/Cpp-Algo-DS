/*
Nearest Greater to left
Nearest Greater to right/ next largest element
Nearest smaller to left
Nearest smaller to right

Similar concept
*/

/*
Given an array, traverse over it and find the nearest greater element
[1,3,2,4]
output-
[3,4,4,-1]

//O(n^2) solution

int ans[n];
for(int i=0;i<n-1;i++){
    int val=given_array[i];
    for(int j=i+1;j<n;j++){
        if(given_array[i]>val){
            ans[i]=given_array[i]; break;
        }
    }
}

Since the inner for loop's j is dependent of outer for loop's i, so we can use stack here.

//Solution using stack

*/

#include<bits/stdc++.h>
using namespace std;



int main(){
    int n=4;
    int arr[4]={1,3,2,4};
    vector<int> v;
    stack<int> s;

for(int i=n-1;i>=0;i--){ //travelling reverse
    if(s.size()==0){
        v.push_back(-1);
    }
    else if(s.size()>0 && s.top()>arr[i]){
        v.push_back(s.top());
    }
    else if(s.size()>0 && s.top()<=arr[i]){
        while(s.size()>0 && s.top()<=arr[i]){
            s.pop();
        }
        if(s.size()==0){
            v.push_back(-1);
        }
        else{
            v.push_back(s.top());
        }
    }
    s.push(arr[i]);
}
reverse(v.begin(),v.end());
for(auto it:v){
    cout<<it<<" ";
}
   return 0;
}