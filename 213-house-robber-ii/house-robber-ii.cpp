const int N = 100;
int DP[N + 1];

class Solution {
public:

    int solve(vector<int>& nums, int idx, int end) {
        if(idx > end) {
            return 0;
        }
        if(DP[idx] != -1) {
            return DP[idx];
        }
        // pick
        int ans1 = nums[idx] + solve(nums, idx + 2, end);
        // not pick
        int ans2 = solve(nums, idx + 1, end);
        return DP[idx] = max(ans1, ans2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        // Case 1: take houses 0 -> n-2
        memset(DP, -1, sizeof(DP));
        int ans1 = solve(nums, 0, n - 2);
        // Case 2: take houses 1 -> n-1
        memset(DP, -1, sizeof(DP));
        int ans2 = solve(nums, 1, n - 1);

        return max(ans1, ans2);
    }
};