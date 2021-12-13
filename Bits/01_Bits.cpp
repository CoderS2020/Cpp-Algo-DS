#include<iostream>
using namespace std;

//Left shift everywhere

//To get the bit at specified position
int GetBit(int no,int pos){
    if((no&(1<<pos))!=0){
        return 1;
    }
    else{
        return 0;
    }
}

//Setting means updating 1 and unsetting/clearing means updating 0
int SetBit(int no,int pos){
   return (no|(1<<pos));
}

//Clearing / Unsetting means updating to 0
int ClearBit(int no,int pos){
    return ((~(1<<pos))&no);
}

//Updating bit i.e. first clearing and then setting using or
int UpdatingBit(int no,int pos,int val){
    int mask=((~(1<<pos))&no);
    return (mask|(val<<pos));
}

int main(){
    int no;
    cin>>no;
    int pos;
    cin>>pos;
    
    // cout<<GetBit(no,pos);
    //cout<<SetBit(no,pos);
    // cout<<ClearBit(no,pos);
    cout<<UpdatingBit(no,pos,1);
    return 0;
}