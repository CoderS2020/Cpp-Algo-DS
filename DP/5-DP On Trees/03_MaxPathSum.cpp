/*
int solve(Node * root, int & res){
    if(root==NULL) return 0;

    int left=solve(root->left,res);
    int right=solve(root->right,res);

    int temp= max(root->val,root->val+max(left,right)); //we took max here because we may get -ve values
    int ans=max(temp, root->val+left+right);    
    res=max(res,ans);

    return temp; //temp returned for next recursive call calculation
}

int main(){
    int res=INT_MIN;
    solve(root,res);
    return res;

}
*/