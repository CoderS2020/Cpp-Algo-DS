/*
//If at any floor the egg breaks then go downwards to find threshold floor
//or if it does not break then go upwards 

int solve(int e,int f){
    //Base condition
    if(f==0 || f==1) return f; //If there is no floor then return 0, if there is 1 floor in worst case it will be 1st floor from where the egg breaks
    if(e==1) return f; //In worst case threshold floor will be the topmost floor(fth floor)

    int mini=INT_MAX;

    for(int k=1;k<=f;k++){
        int breaks=solve(e-1,k-1);
        int nobreak=solve(e,f-k); //the above remaining floors

        //Add 1 because we have performed 1 attempt. We take max because we want for worst case.
        //So from breaks,nobreaks whichever takes max attempts they are chosen bcz we want for worst case.
        int tempans=1+max(breaks,nobreak); 
        mini=min(mini,tempans);
    }
    return mini;

}
*/

/*
DP:Memoized
int t[e+1][f+1];
memset(t,-1);
int solve(int e,int f){
    if(f==0 || f==1) return f;
    if(e==1) return f;

    if(t[e][f]!=-1) return t[e][f];

    int mini=INT_MAX;

    for(int k=1;k<=f;k++){
        int breaks=solve(e-1,k-1);
        int nobreak=solve(e,f-k); 

        int tempans=1+max(breaks,nobreak); 
        mini=min(mini,tempans);
    }
    return t[e][f]=mini;

}
*/

/*
DP:Optimized Memoized
int t[e+1][f+1];
memset(t,-1);
int solve(int e,int f){
    if(f==0 || f==1) return f;
    if(e==1) return f;

    if(t[e][f]!=-1) return t[e][f];

    int mini=INT_MAX;

    for(int k=1;k<=f;k++){
        int breaks,nobreak;
        
        if(t[e-1][k-1]!=-1) breaks=t[e-1][k-1];
        else breaks=solve(e-1,k-1);

        if(t[e][f-k]!=-1) breaks=t[e][f-k];
        else nobreak=solve(e,f-k);         
        

        int tempans=1+max(breaks,nobreak); 
        mini=min(mini,tempans);
    }
    return t[e][f]=mini;

}
*/