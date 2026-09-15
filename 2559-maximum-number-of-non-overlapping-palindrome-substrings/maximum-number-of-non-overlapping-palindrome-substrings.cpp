// class Solution {
// public:
//     bool is_palin(string s, int i , int j){
//        while(i < j){
//         if(s[i] != s[j]){
//             return false;
//         }
//         i++;
//         j--;
//        }

//        return true;
//     }

//     int solve(string &s, int k, vector<vector<int>> &DP, int i, int j, int n){
//         if(i>=n || j>=n){
//             return 0;
//         }

//         if(DP[i][j] != -1){
//             return DP[i][j];
//         }

//         if(is_palin(s,i,j)){
//             int take = 1 +  solve(s, k, DP, j+1, j+k, n);
//             int grow = solve(s, k, DP,i , j+1, n);
//             int slide = solve(s, k, DP, i+1, j+1, n);

//             return DP[i][j] = max({take, grow , slide});
//         }

//         int grow = solve(s, k, DP, i, j+1, n);
//         int slide =  solve(s , k, DP, i+1, j+1, n);
//         return DP[i][j] = max(slide, grow);

//     }
//     int maxPalindromes(string s, int k) {
//         int n = s.length();
//         int i=0;
//         int j=k-1;
//         if(k==1){
//             return n;
//         }
//         vector<vector<int>> DP(n+1,vector<int> (n+1, -1));
//         return solve(s, k, DP, i, j, n);
//     }
// };

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        
        // Edge case: k larger than string length
        if (k > n) return 0;
        
        // Step 1: Precompute palindromes using Expand Around Center
        vector<vector<bool>> is_pal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            // Odd length palindromes (centered at i)
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                is_pal[l][r] = true;
                l--; r++;
            }
            
            // Even length palindromes (centered between i and i+1)
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                is_pal[l][r] = true;
                l--; r++;
            }
        }
        
        // Step 2: 1D DP - dp[i] = max non-overlapping palindromes from index i
        vector<int> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Skip current character
            dp[i] = dp[i + 1];
            
            // Option 2: Find valid palindrome starting at position i
            // Start j from i+k-1 to ensure minimum length k
            for (int j = i + k - 1; j < n; j++) {
                if (is_pal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                    break;  // Found smallest valid palindrome, stop checking longer ones
                }
            }
        }
        
        return dp[0];
    }
};