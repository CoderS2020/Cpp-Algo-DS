#include<iostream>
using namespace std;
/*
void reverse(string s){
    if(s.length()==0){
        return;
    }

    string ros=s.substr(1);
    reverse(ros);
    cout<<s[0];
}


int main(){
    reverse("binod");

    return 0;
}*/

//Replace pi with 3.14 in a string
/*
void replacePI(string s){
    if(s.length()==0){
        return ;
    }

    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacePI(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePI(s.substr(1));
    }
}



int main(){

    replacePI("pippppiiiiipi");
    return 0;
}*/


//Tower of Hanoi
/*
void towerofHanoi(int n,char src,char dest,char helper){
    if(n==0){ //base case
        return ;
    }
    towerofHanoi(n-1,src,helper,dest);
    cout<<"Move from "<<src<<"to"<<dest<<endl;
    towerofHanoi(n-1,helper,dest,src);

}



int main(){
    towerofHanoi(3,'A','C','B');
    return 0;
}*/

//Remove all adjacent duplicates from the string
/*string removeDup(string s){
    if(s.length()==0){ //base condition
        return "";
    }

    char ch=s[0];
    string ans=removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}

int main(){
    cout<<removeDup("aaaabbbeeecdddd");
    return 0;
}*/


//Move all x to the end of the string
/*
string moveallX(string s){
    if(s.length()==0){ //base
        return "";
    }

    char ch=s[0];
    string ans=moveallX(s.substr(1));
    if(ch=='x'){
        return (ans+ch);
    }
        return (ch+ans);

}

int main(){
    cout<<moveallX("axxbdcefxhix");
    return 0;
}*/

//Generate all substrings of a string
/*
void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }

    char ch=s[0];
    string ros=s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}


int main(){

    subseq("ABS","")
    return 0;
}*/


//Generate substrings with ASCII number
/*void subseq(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);

    subseq(ros,ans);
    subseq(ros,ans+ch);
    subseq(ros,ans+ to_string(code));
    
}

int main(){

    subseq("AB","");
    return 0;
}*/


//Print all possible words from phone digits
/*
string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }

    char ch=s[0];
    string code=keypadArr[ch-'0'];
    string ros=s.substr(1);

    for(int i=0;i<code.length();i++){
        keypad(ros,ans+code[i]);
    }


}


int main(){

    keypad("23","");


    return 0;
}*/