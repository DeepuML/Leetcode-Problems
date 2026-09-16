class Solution {
public:
    int solve(string &a, string &b, int n, int m, vector<vector<int>> &DP) {
        if(n == 0 || m == 0) {
            return 0;
        }
        if(DP[n][m] != -1) {
            return DP[n][m];
        }
        if(a[n-1] == b[m-1]) {
            return DP[n][m] = 1 + solve(a, b, n-1, m-1, DP);
        }
        else {
            int a1 = solve(a, b, n-1, m, DP);
            int b1 = solve(a, b, n, m-1, DP);
            return DP[n][m] = max(a1, b1);
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();

        string b = s;
        reverse(b.begin(), b.end());

        vector<vector<int>> DP(n+1, vector<int>(n+1, -1));
        return solve(s, b, n, n, DP);
    }
};