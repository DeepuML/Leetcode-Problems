class Solution {
public:
    int solve(int curr, int n, vector<int> &dp){
        if(curr==n){
            return 1; 
        }
        if(curr>n){
            return 0;
        }
        if(dp[curr]!=-1){
            return dp[curr];
        }
        // jump 1 
        int ans1 = solve(curr+1, n, dp);
        //  jump 2
        int ans2 = solve(curr+2, n, dp);

        return dp[curr] = ans1+ ans2;
    }
    int climbStairs(int n) {
        int curr = 0;
        vector<int> dp(n+1,-1);
        return solve(curr, n,dp);   
    }
};