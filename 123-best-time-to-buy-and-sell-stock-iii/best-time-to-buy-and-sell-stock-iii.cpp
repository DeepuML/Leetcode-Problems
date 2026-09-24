const int BUY = 0;
const int SELL = 1;

int DP[100000][4];

class Solution {
public:
    int solve(vector<int>& prices, int idx, int t_t, int event) {

        // 4 events -> B -> S -> B -> S
        if (idx == prices.size() || event == 4) {
            return 0;
        }

        // Already calculated
        if (DP[idx][event] != -1) {
            return DP[idx][event];
        }

        // Skip the day
        int ans1 = solve(prices, idx + 1, t_t, event);

        // Decide whether we need to BUY or SELL
        t_t = (event % 2 == 0) ? BUY : SELL;

        int ans2 = 0;

        if (t_t == BUY) {
            // Buy
            ans2 = -prices[idx] + solve(prices, idx + 1, t_t, event + 1);
        } 
        else {
            // Sell
            ans2 = prices[idx] + solve(prices, idx + 1, t_t, event + 1);
        }
        return DP[idx][event] = max(ans1, ans2);
    }

    int maxProfit(vector<int>& prices) {
        memset(DP, -1, sizeof(DP));
        return solve(prices, 0, BUY, 0);
    }
};