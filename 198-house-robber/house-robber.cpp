const int N=100;
int DP[N+1];
class Solution {
public:
    int solve(vector<int> nums, int idx){
        if(idx >= nums.size()){
            return 0;
        }
        if(DP[idx]!=-1){
            return DP[idx];
        }
        //  take 
        int ans1 = nums[idx] +  solve(nums, idx+2);
        // not take 
        int ans2 = solve(nums, idx+1);

        return DP[idx] = max(ans1, ans2);

    }
    int rob(vector<int>& nums) {
        memset(DP, -1, sizeof(DP));
        return solve(nums, 0);
    }
};