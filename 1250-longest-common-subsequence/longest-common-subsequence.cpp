class Solution {
public:
    int solve(string &a, string &b , int n, int m , vector<vector<int>> &DP){
        if(n==0 || m==0){
            return 0;
        }

        if(DP[n][m] != -1){
            return DP[n][m];
        }

        if(a[n-1]==b[m-1]){
                return DP[n][m] = 1 + solve(a,b,n-1, m-1, DP);
        }
        else{
            int a1 =  solve(a,b,n-1, m,DP);
            int b1 = solve(a,b,n, m-1,DP);
            return DP[n][m] = max(a1, b1);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> DP(n+1, vector<int>(m+1, -1));
        return solve(text1, text2, n,m , DP);
    }
};