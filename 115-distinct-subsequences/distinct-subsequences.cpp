class Solution {
public:
    int solve(const string& s, const string& t, int i, int j,
              vector<vector<long long>>& dp) {

        // t completely matched
        if (j == t.length()) {
            return 1;
        }
        // s finished but t is still remaining
        if (i == s.length()) {
            return 0;
        }
        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            // Include s[i]
            long long include = solve(s, t, i + 1, j + 1, dp);
            // Exclude s[i]
            long long exclude = solve(s, t, i + 1, j, dp);
            return dp[i][j] = include + exclude;
        } else {
            // Characters don't match
            return dp[i][j] = solve(s, t, i + 1, j, dp);
        }
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        return solve(s, t, 0, 0, dp);
    }
};