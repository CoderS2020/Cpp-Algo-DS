//Vectors act like dynamic array, we dont mention number of elements, and we can add them as per requirements without any limits for addition.

#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>


using namespace std;
/*
int main(){

    vector <int> v; //Declaring a vector
    
    //Pushing in vector from back
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //Printing values of vector
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    cout<<endl;

    //Declaring an iterator 
    vector <int>::iterator it;

    //Printing values using iterator
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    // 3.Using "auto" keyword- compiler 'auto'matically decides return type
    for(auto element:v){
        cout<<element<<endl;        
    }

    v.pop_back(); //removes last element
    for(auto element:v){
        cout<<element<<endl;        
    }
    
    //Can also mention size of vector, here 3
    // vector <int> v2(3);

    //vector of size 3 with every element as 5
    vector <int> v2(3,5);
    
    swap(v,v2);  //swaps elements of both vectors.
    
    //sort and other functions can be learnt through cpp website
        
    return 0;
}*/


// pair- alows to store pair of  //Declaring a pair
    // pair <int,char> p;
    // p.first=3;
    // p.second='f';

bool myCompare(pair<int , int> p1, pair <int,int> p2){
    return p1.first<p2.first;
}

int main(){

   

    int arr[]={10,16,7,14,5,3,12,9};
    vector <pair<int, int>> v;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
       
        v.push_back(make_pair(arr[i],i));
    }

    sort(v.begin(),v.end(),myCompare);

    for(int i=0;i<v.size();i++){
        arr[v[i].second]=i;
    }

    for(int i=0;i<v.size();i++){
        cout<<arr[i];
    }
    
    return 0;
}