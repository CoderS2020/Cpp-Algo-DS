//Important
//On a 2*3 board, there are five tiles labelled 1 to 5, and an empty square
//represented by 0. A move consists of chossing 0 and 4 directionally adjacent
// number and swapping it. Given the puzzle board, print the least number of 
//moves required so that the state of the board is solved. If it is impossible
// for the state of the board to be solved, print -1
#include<bits/stdc++.h>
using namespace std;

string swapCharacters(string s,int idx,int swapIndex){
    char ch=s[idx];
    char ch1=s[swapIndex];
    s[idx]=ch1;
    s[swapIndex]=ch;
    return s;
}



int main(){
    int arr[2][3];
    string target="123450";
    string initial="";
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
            initial.append(to_string(arr[i][j]));
        }
    }
    
    queue<string> q;
    // 0 1 2
    // 3 4 5
    //If 0 is at 0th index then it can be swapped with 1,3 and so on
                                        //0    //1    //2    //3   //4     //5
    vector<vector<int>> swappingIndex={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{4,2}};
    map<string,int> isAddedAlready;
    q.push(initial);
    int level=0;
    bool ans=false;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            string rem=q.front();
            q.pop();
  
            if(rem==target){
                ans=true;
                cout<<level;
            }

            int idx=-1;
            //Find index of '0'
            for(int i=0;i<rem.length();i++){
                if(rem[i]=='0'){
                    idx=i;
                    break;
                }
            }
 
            vector<int> swappingPosition=swappingIndex[idx];
            for(int i=0;i<swappingPosition.size();i++){
                //swap the nos
                string toBeAdded=swapCharacters(rem,idx,swappingPosition[i]);
              
                //if the swapped no is already added then dont push to queue               
                if(isAddedAlready.find(toBeAdded)==isAddedAlready.end()){
                    q.push(toBeAdded);
                    isAddedAlready[toBeAdded]=1;
                }
            }


        }
        level++;
    }
    if(!ans){
        cout<<"-1\n";
    }
    


   return 0;
}