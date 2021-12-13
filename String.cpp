#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
void toUpper(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }
    cout<<str;
}

void toLower(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
    }
    cout<<str<<endl;

}


int main(){

    string str="Swaraj Pawar";
    toLower(str);
    toUpper(str);
    
    return 0;
}*/
/*
int main(){
    string s="Swaraj";
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s;

    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s;
}*/

//Form the biggest number from the numeric string
/*
int main(){
    string s="41536";
    sort(s.begin(),s.end(),greater<int>());
    cout<<s<<endl;
    return 0;
}*/

//Find the character that occurs for maximum time
/*
int main(){
    string s="dfslkerndfl";
    int freq[26];
    
    for(int i=0;i<26;i++){
        freq[i]=0;
    }

    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }

    char ans='a';
    int maxF=0;
    for(int i=0;i<26;i++){
        if(freq[i]>maxF){
            maxF=freq[i];
            ans=i+'a';
        }
    }
    cout<<ans<<endl<<maxF<<endl;
    return 0;
}*/