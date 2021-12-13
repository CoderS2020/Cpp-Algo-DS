#include<iostream>
using namespace std;

//Palindrome
/*int main(){
    int n;
    cin>>n;
    
    char arr[n+1];
    cin>>arr;

    bool check=1;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-1-i]){
            check=0;
            break;
        }
    }
    if(check==1){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }
    
    return 0 ;
}*/

//Largest word in a sentence
/*int main(){

    int n;
    cin>>n;
    
    char arr[n+1];
    cin.getline(arr,n);
    

    int i=0,currLen=0,maxLen=0;
    int st=0,maxst=0;
    while(1){
       
        if(arr[i]==' ' || arr[i]=='\0'){
            if(maxLen<currLen){
                maxLen=currLen;
                maxst=st;
            }
            currLen=0;
            st=i+1;
        }
        else{
            currLen++;
        }

        if(arr[i]=='\0'){
            break;

        }
        i++;

    }
    cout<<maxLen<<endl;
    for(int i=0;i<maxLen;i++){
        cout<<arr[i+maxst];
    }

    return 0;
}*/