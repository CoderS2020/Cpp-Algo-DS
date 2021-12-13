#include<bits/stdc++.h>
using namespace std;

//Input output method makes use of tree
//Leaf Node gives the base condition

void solve(string input,string output){
    if(input.length()==0){ //base condition
        cout<<output<<" ";
        return;
    }
//For every decision there will be 2 possibilities in a tree
   //Initialize output1,output2 exclusively otherwise sometimes it causes problems
    string output1=output; //The successive outputs are derived from previous outputs in a tree 
    string output2=output;
// Out of the 2 outputs one output accepts whereas other output does not accept
    output2.push_back(input[0]);
    input.erase(input.begin()+0); //Delete the first character in input string
    solve(input,output1);
    solve(input,output2);
    return;
};

int main(){
    string input,output="";
    cin>>input;
    solve(input,output);

   return 0;
}

