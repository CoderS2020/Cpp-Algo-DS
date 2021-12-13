/*
Starting and ending nodes should be leaf nodes.
int solve(Node * root, int & res){
    if(root==NULL) return 0;

    int left=solve(root->left,res);
    int right=solve(root->right,res);

    int temp= max(l,r)+root->val;
    if(root->left==NULL && root->right==NULL) temp=max(temp,root->val); //you may or may not write this

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