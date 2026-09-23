const int BUY = 0;
const int SELL = 1;

int DP[30000][2];

class Solution {
public:

    int solve(vector<int>& prices, int idx, int trans_type) {

        if (idx == prices.size()) {
            return 0;
        }

        // Already calculated
        if (DP[idx][trans_type] != -1) {
            return DP[idx][trans_type];
        }

        // Skip the day
        int ans1 = solve(prices, idx + 1, trans_type);

        // Perform action
        int ans2 = 0;

        if (trans_type == BUY) {
            // Buy
            ans2 = -prices[idx] + solve(prices, idx + 1, SELL);
        }
        else {
            // Sell
            ans2 = prices[idx] + solve(prices, idx + 1, BUY);
        }

        return DP[idx][trans_type] = max(ans1, ans2);
    }

    int maxProfit(vector<int>& prices) {

        memset(DP, -1, sizeof(DP));

        return solve(prices, 0, BUY);
    }
};