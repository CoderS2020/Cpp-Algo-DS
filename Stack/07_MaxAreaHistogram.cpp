/*
int n=7;
int arr[n]={6,2,5,7,5,1,6};
Heights of building given.Find max area of rectangle possible

Optimized Approach:-
Find nearest smaller to left and nearest smaller to right , subtract right - left - 1 to get index,
then area=w*arr[i]
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=7;
    int arr[n]={6,2,5,7,5,1,6};
    vector<int> right;
    vector<int>left;
    stack<pair<int,int>> s;

    //NSL to find left 
    int pseudoindex=-1;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            left.push_back(pseudoindex);
        }
        else if(s.size()>0 && s.top().first<arr[i]){
            left.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first>=arr[i]){
            while(s.size()>0 && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                left.push_back(pseudoindex);
            }
            else if(s.top().first<arr[i]){
                left.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }

    stack<pair<int,int>> st;
    //NSR to find right
    pseudoindex=n+1;
    for(int i=n-1;i>=0;i--){
        if(st.size()==0){
            right.push_back(pseudoindex);
        }
        else if(st.size()>0 && st.top().first<arr[i]){
            right.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first>=arr[i]){
            while(st.size()>0 and st.top().first>=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                right.push_back(pseudoindex);
            }
            else if(st.top().first<arr[i]){
                right.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
    }

    reverse(right.begin(),right.end());
    int maxi=INT_MIN;
    int width[n];
    for(int i=0;i<n;i++){
        width[i]=right[i]-left[i]-1;
    }
    int area[n];
    for(int i=0;i<n;i++){
        area[i]=width[i]*arr[i];
        maxi=max(area[i],maxi);
    }
    cout<<maxi<<endl;

   return 0;
}