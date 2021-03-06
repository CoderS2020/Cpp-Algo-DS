#include<iostream>
#include<stack>
using namespace std;
/*
void reverseSentence(string s){
    stack <string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while (s[i]!=' ' && i<s.length())
        {
            word+=s[i];
            i++;
        }
        st.push(word);
        
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}


int main(){
    string s="Hey, how are you doing?";
    reverseSentence(s);
   return 0;
}*/

void insertAtBottom(stack <int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}


void reverse(stack<int> &st){

    if(st.empty()){
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}



int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }cout<<endl;
    return 0;
}