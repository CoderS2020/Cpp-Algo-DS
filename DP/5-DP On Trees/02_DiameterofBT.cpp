/*
int solve(Node * root, int & res){
    if(root==NULL) return 0;

    int left=solve(root->left,res);
    int right=solve(root->right,res);

    int temp= 1+max(left,right);
    int ans=max(temp, 1+left+right);    
    res=max(res,ans);

    return temp; //temp returned for next recursive call calculation
}

int main(){
    int res=INT_MIN;
    solve(root,res);
    return res;

}
*/