const int BUY = 0;
const int SELL = 1;
const int N = 100000;
int DP[N][2];

class Solution {
public:
    int solve(vector<int>& prices, int idx, int state) {
        // Base case
        if (idx >= prices.size()) {
            return 0;
        }
        // Already calculated
        if (DP[idx][state] != -1) {
            return DP[idx][state];
        }
        // Skip the day
        int ans1 = solve(prices, idx + 1, state);
        // Perform action
        int ans2 = 0;
        if (state == BUY) {
            // Buy
            ans2 = -prices[idx] + solve(prices, idx + 1, SELL);
        } else {
            // Sell + cooldown
            ans2 = prices[idx] + solve(prices, idx + 2, BUY);
        }
        return DP[idx][state] = max(ans1, ans2);
    }

    int maxProfit(vector<int>& prices) {
        memset(DP, -1, sizeof(DP));
        return solve(prices, 0, BUY);
    }
};