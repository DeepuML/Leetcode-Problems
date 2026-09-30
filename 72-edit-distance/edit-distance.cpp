const int n = 500;
int DP[n+1][n+1];

class Solution {
public:
    int solve(string &word1, string &word2, int i, int j) {
        // Base cases
        if(i == word1.length()) {
            return word2.length() - j;
        }
        if(j == word2.length()) {
            return word1.length() - i;
        }
        // Memoization
        if(DP[i][j] != -1) {
            return DP[i][j];
        }
        if(word1[i] != word2[j]) {
            // Replace
            int ans1 = 1 + solve(word1, word2, i+1, j+1);
            // Delete from word1 / Insert into word2
            int ans2 = 1 + solve(word1, word2, i+1, j);
            // Delete from word2 / Insert into word1
            int ans3 = 1 + solve(word1, word2, i, j+1);
            return DP[i][j] = min({ans1, ans2, ans3});
        }
        // Characters are same
        return DP[i][j] = solve(word1, word2, i+1, j+1);
    }
    int minDistance(string word1, string word2) {
        memset(DP, -1, sizeof(DP));
        return solve(word1, word2, 0, 0);
    }
};