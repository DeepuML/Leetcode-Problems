class Solution {
public:
    int solveusingMemoization(int n, vector<int>&dp){
        //base case 
        if(n==1 || n==0){
            return n;
        }
        // if ans already exist then return
        if(dp[n] != -1){
            return dp[n];
        }

        // recursion
        dp[n]= solveusingMemoization(n-1,dp)+solveusingMemoization(n-2,dp);
        return dp[n];
    }

    int fib(int n){
        vector<int> DP(n+1, -1);
        int ans=solveusingMemoization(n,DP);
        return ans;
    }
};