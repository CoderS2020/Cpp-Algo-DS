#include<bits/stdc++.h>
using namespace std;

//There are generally two ways in which you can deal with array recursion, they are mentioned
//in following 2 problems

// https://leetcode.com/problems/combination-sum/
//Combination Sum
/*class Solution{
private:
    void findCombination(int ind, int target, vector<int> & arr, vector<vector<int>> & ans, vector<int> & ds){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }

        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind,target-arr[ind], arr,ans,ds);
            ds.pop_back();
        }
        findCombination(ind+1,target,arr,ans,ds);
    };
public:
    vector<vector<int>> combinationSum(vector<int> & candidates,int target){
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }

};
*/


//Combination Sum2 : https://leetcode.com/problems/combination-sum-ii/
/*
class Solution {
private:
    void findCombination(int ind, int target, vector<int> & arr, vector<vector<int>> & ans, vector<int> & ds){
        if(target==0){
            ans.push_back(ds); return ;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue; //i> ind bcz if there is only last element that satisifes the condition
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombination(i+1,target-arr[i], arr,ans,ds);
            ds.pop_back(); //dont forget to pop back
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
};
*/


//Palindrome partitioning
//https://leetcode.com/problems/palindrome-partitioning/
/*
class Solution{
    public:
        vector<vector<string>> partition(string s){
            vector<vector<string>> res;
            vector<string> path;
            func(0,s,path,res);
            return res;
        }

        void func(int index,string s,vector<string> & path, vector<vector<string>> & res){
            if(index==s.size()){
                res.push_back(path);
                return;
            }
            for(int i=index;i<s.size();i++){
                if(isPalindrome(s,index,i)){
                    path.push_back(s.substr(index,i-index+1));
                    func(i+1,s,path,res);
                    path.pop_back();
                }
            }
        }
        bool isPalindrome(string s, int start, int end){
            while(start<=end){
                if(s[start++]!=s[end--]){
                    return false;
                }
            }
            return true;
        }
};

*/


//Subset Sums
/*class Solution{
    public:
        void func(int ind,int sum,vector<int> & arr, int N,vector<int> &sumSubset){
            if(ind==N){
                sumSubset.push_back(sum);
                return;
            }

            func(ind+1,sum+arr[ind],arr,N,sumSubset);

            func(ind+1,sum,arr,N,sumSubset);
        }
        vector<int> subsetSums(vector<int> arr,int N){
            vector<int> sumSubset;
            func(0,0,arr,N,sumSubset);
            sort(sumSubset.begin(),sumSubset.end());
            return sumSubset;
        }
};*/



//Subsets II
//https://leetcode.com/problems/subsets/
/*
class Solution {
private:
    void findSubsets(int ind, vector<int> & nums, vector<int> & ds, vector<vector<int>> & ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue; //first element is considered (i!=ind)
            ds.push_back(nums[i]);
            findSubsets(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;
    };
};
*/


//Permutaion Sequence
//https://leetcode.com/problems/permutation-sequence/
/*
class Solution{
    public:
        string getPermutation(int n,int k){
            int fact=1;
            vector<int> numbers;
            for(int i=1;i<n;i++){
                fact=fact*i;
                numbers.push_back(i);
            }
            numbers.push_back(n);
            string ans="";
            k=k-1;
            while(true){
                ans=ans+to_string(numbers[k/fact]);
                numbers.erase(numbers.begin()+k/fact);
                if(numbers.size()==0){
                    break;
                }
                k=k%fact;
                fact=fact/numbers.size();
            }
            return ans;
        }
};*/

//Permutations

//1st Approach: TC-n!*n SC- O(n)+O(n)
/*class Solution{
    private:
        void recurPermute(vector<int> & ds,vector<int> & nums,vector<vector<int>> & ans,int freq[]){
            if(ds.size()==nums.size()){
                ans.push_back(ds);
                return;
            }
            for(int i=0;i<nums.size();i++){
                if(!freq[i]){
                    ds.push_back(nums[i]);
                    freq[i]=1;
                    recurPermute(ds,nums,ans,freq);
                    freq[i]=0;
                    ds.pop_back();
                }
            }
        }
    public:
        vector<vector<int>> permute(vector<int> & nums){
            vector<vector<int>> ans;
            vector<int> ds;
            int freq[nums.size()];
            for(int i=0;i<nums.size();i++) freq[i]=0;
            recurPermute(ds,nums,ans,freq);
            return ans;
        }
};
*/

//2nd Approach TC-n!*n SC No extra space
/*class Solution{
    private:
        void recurPermute(int index,vector<int> & nums, vector<vector<int>> & ans){
            if(index==nums.size()){
                ans.push_back(nums);
                return;
            }
            for(int i=index;i<nums.size();i++){
                swap(nums[index],nums[i]);
                recurPermute(index+1,nums,ans);
                swap(nums[index],nums[i]);
            }
        }
    public:
        vector<vector<int>> permute(vector<int> & nums){
            vector<vector<int>> ans;
            recurPermute(0,nums,ans);
            return ans;
        }
};*/

//Sudoku Solver
/*
class Solution{
    public:
        void solveSudoku(vector<vector<char>> & board){
            solve(board);
        }
        bool solve(vector<vector<char>> & board){
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]=='.'){
                        for(char c='1';c<='9';c++){
                            if(isValid(board,i,j,c)){
                                board[i][j]=c;

                                if(solve(board)==true)return true;
                                else board[i][j]='.';
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        bool isValid(vector<vector<char>> & board, int row,int col,char c){
            for(int i=0;i<9;i++){
                if(board[i][col]==c) return false;

                if(board[row][i]==c) return false;

                if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c) return false;
            }
            return true;
        }
};
*/

// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
/*
bool isSafe(int node,int color[],bool graph[101][101],int n, int col){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col){
            return false;
        }
    }
    return true;
};

bool solve(int node,int color[],int m,int N,bool graph[101][101]){
    if(node==N) return true;

    for(int i=1;i<=m;i++){
        if(isSafe(node,color,graph,N,i)){
            color[node]=i;
            if(solve(node+1,color,m,N,graph)) return true;
            color[node]=0;
        }
    }
    return false;
};

bool graphColoring(bool graph[101][101],int m,int N){
    int color[N]={0};
    if(solve(0,color,m,N,graph)) return true;
    return false;
};
*/