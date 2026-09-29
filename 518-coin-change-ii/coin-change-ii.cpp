const int N = 300;
const int am = 5000;
int DP[N+1][am+1];

class Solution {
public:

    int solve(int idx, int amount, vector<int>& coins, int curr_sum) {
        // amount achieved
        if(curr_sum == amount) {
            return 1;
        }
        // no coins left
        if(idx == coins.size()) {
            return 0;
        }
        if(DP[idx][curr_sum] != -1) {
            return DP[idx][curr_sum];
        }

        // take
        int ans1 = 0;
        if(curr_sum + coins[idx] <= amount) {
            ans1 = solve(idx, amount, coins, curr_sum + coins[idx]);
        }
        // not take
        int ans2 = solve(idx + 1, amount, coins, curr_sum);
        DP[idx][curr_sum] = ans1 + ans2;
        return DP[idx][curr_sum];
    }

    int change(int amount, vector<int>& coins) {
        memset(DP, -1, sizeof(DP));
        return solve(0, amount, coins, 0);
    }
};