const int N = 1e4;
int DP[N+1][N+1];

class Solution {
public:
    int solve(vector<int> &nums, int idx, int prev) {

        if(idx == nums.size()) {
            return 0;
        }
        if(DP[idx][prev + 1] != -1) {
            return DP[idx][prev + 1];
        }
        // not take
        int ans1 = solve(nums, idx + 1, prev);

        // take
        int ans2 = 0;
        if(prev == -1 || nums[prev] < nums[idx]) {
            ans2 = 1 + solve(nums, idx + 1, idx);
        }
        return DP[idx][prev + 1] = max(ans1, ans2);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(DP, -1, sizeof(DP));
        return solve(nums, 0, -1);
    }
};