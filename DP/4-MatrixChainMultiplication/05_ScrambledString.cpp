/*

2 cases- we may swap or we may not swap
If there is no swap then compare beginning of first string with beginning of second string and end of first string with end of second string
If there is a swap then compare beginning of first string with end of second string(compare alternate start-end)

//Recursive
bool solve(string a , string b){
    if(a.compare(b)==0) return true;

    if(a.length()<=1) return false; //on line 9 if it was length 1 but same then return true, else if it is empty or single character(not equal) then return false

    int n=a.length();
    bool flag=false;
    for(int i=1;i<n;i++){
        if((solve(a.substr(0,i), b.substr(n-i,i)==true )  //start of first string with end of second string
        && solve(a.substr(i,n-i), b.substr(0,n-i)))           //start of first string with end of second string
            ||
        (solve(a.substr(0,i), b.substr(0,i))==true
        && solve(a.substr(i,n-i), b.substr(i,n-i))==true ) //comparing beginning with end
        ){
            flag=true;
            break;
        }
    }
    return flag;
}

//DP:Memoized
unordered_map<string,bool> mp;
bool solve(string a , string b){
    if(a.compare(b)==0) return true;

    if(a.length()<=1) return false; 

    string key=a;
    key.push_back(' ');
    key.append(b);
    if(mp.find(key)!=mp.end()) return mp[key];


    int n=a.length();
    bool flag=false;

    for(int i=1;i<n;i++){
        if((solve(a.substr(0,i), b.substr(n-i,i))==true )
        && solve(a.substr(i,n-i), b.substr(0,n-i) ) )     
            ||
        (solve(a.substr(0,i), b.substr(0,i))==true
        && solve(a.substr(i,n-i), b.substr(i,n-i))==true )
        ){
            flag=true;
            break;
        }
    }
    return mp[key]=flag;
}



*/