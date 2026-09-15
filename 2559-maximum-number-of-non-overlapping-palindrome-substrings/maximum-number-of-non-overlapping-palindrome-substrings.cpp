class Solution {
public:

    bool isPal(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int k, vector<int> &dp, int i) {
        int n = s.length();
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        // Don't take anything starting at i
        int ans = solve(s, k, dp, i + 1);
        // Try every palindrome of length >= k
        for (int j = i + k - 1; j < n; j++) {
            if (isPal(s, i, j)) {
                int take = 1 + solve(s, k,  dp,j + 1);
               ans = max(ans, take);
            }
        }
        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {
            int n = s.length();
          if(k==1){
            return n;
        }
        vector<int> dp(n, -1);
        return solve(s, k, dp, 0);
    }
};