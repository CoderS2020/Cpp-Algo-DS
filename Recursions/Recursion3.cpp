#include<iostream>
using namespace std;

//Print all possible permutations of a string
/*void permutations(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permutations(ros,ans+ch);
    }
}


int main(){

    permutations("ABC","");
    return 0;
}*/


//Count the number of paths possible from start point to end point in gameboard
/*int countPath(int start,int end){
    if(start==end){
        return 1;
    }
    if(start>end){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        count+=countPath(start+i,end);
    }
    return count;

}

int main(){
    cout<<countPath(0,3);
    return 0;
}*/

//Count the number of paths possible in a maze
/*int countPathMaze(int n,int i,int j){

    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1);
}


int main(){
    cout<<countPathMaze(3,0,0);
    return 0;
}*/