//https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1
#include<bits/stdc++.h>
using namespace std;

void solve(string input,string output){
    if(input.length()==0){
        cout<<output<<" ";
        return;
    }
    string output1=output;
    string output2=output;
    //Since 'A'(first element) is already included in main(), so we have to take care of previous spaces and not after spaces.
    output1.push_back('_'); //Space is denoted by '_'
    output1.push_back(input[0]);
    output2.push_back(input[0]);
    input.erase(input.begin()+0);
    solve(input,output1);
    solve(input,output2);
    return;

}


int main(){
    string input,output="";
    cin>>input;
    output.push_back(input[0]); //we put it manually because first element can never be empty space
    input.erase(input.begin()+0);
    solve(input,output);


   return 0;
}