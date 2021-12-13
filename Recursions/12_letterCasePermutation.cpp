#include<bits/stdc++.h>
using namespace std;

void solve(string input,string output,vector<string> &v){
   if(input.length()==0){
      v.push_back(output);
      return ;
   }
   if(isalpha(input[0])){
      string output1=output;
      string output2=output;
      //The input can be lower or uppercase-> so we have to take care that its opposite case is pushed to output , so we push both cases (upper and lower)
      output1.push_back(tolower(input[0]));
      output2.push_back(toupper(input[0]));
      input.erase(input.begin()+0);
      solve(input,output1,v);
      solve(input,output2,v);
      return;
   }
   else{
      string output1=output;
      output1.push_back(input[0]);
      input.erase(input.begin()+0);
      solve(input,output1,v);
   }
   
}


vector<string> answer(string s){

   string input=s;
   string output="";
   vector<string> v;
   solve(input,output,v);
   return v;
   
}

int main(){
   string input,output="";
   cin>>input;
   vector<string> ans=answer(input);
   for(auto i=ans.begin();i!=ans.end();i++){
      cout<<*i<<" ";
   }

    
   return 0;
}