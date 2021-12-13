#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    //Brute force approach (O(n^2))
    // int flag=0;
    // for(int i=0;i<n-k+1;i++){
        
    //     for(int j=0;j<k;j++){
    //         if(v[i+j]<0){
    //             cout<<v[i+j]<<" "; 
    //             flag=1; break;
    //         }
    //     }
    //     if(flag==0){
    //         cout<<"0"<<" ";
    //     }
    //     flag=0;
    // }

    //Using sliding window approach
    queue<int> neg;
    vector <int> ans;
    int i=0,j=0;
    while(j<n){
        if(v[j]<0) //condition
            neg.push(v[j]);
        
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(neg.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(neg.front()); //ans
                if(v[i]==neg.front()){ //remove unwanted elements
                    neg.pop();
                }
                
            }
            i++;j++;
        }
    }

    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<*i<<" ";
    }


   return 0;
}