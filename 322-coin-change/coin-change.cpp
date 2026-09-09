class Solution {
public:
    int solve(vector<int>& coins, int amount, int n, vector<vector<int>>& DP) {

        // Amount achieved
        if (amount == 0) {
            return 0;
        }

        // No coins left but amount is still remaining
        if (n == 0) {
            return INT_MAX - 1;
        }

        if (DP[n][amount] != -1) {
            return DP[n][amount];
        }
        if (coins[n - 1] <= amount) {
            // Include current coin: n remains same -> unbounded
            int include = 1 + solve(coins, amount - coins[n - 1], n, DP);
            // Exclude current coin
            int exclude = solve(coins, amount, n - 1, DP);
            return DP[n][amount] = min(include, exclude);
        }
        else {
            return DP[n][amount] = solve(coins, amount, n - 1, DP);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> DP(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins, amount, n, DP);
        if (ans >= INT_MAX - 1) {
            return -1;
        }
        return ans;
    }
};