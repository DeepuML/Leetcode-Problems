class Solution {
public:
    bool solve(vector<int> &nums, int target, int n, vector<vector<int>> &DP){
        if(n==0){
            return false;
        }
        if(target==0){
            return true;
        }

        if(DP[n][target]!=-1){
            return DP[n][target];
        }

        if(nums[n-1]<=target){
            bool include = solve(nums, target-nums[n-1], n-1, DP);
            bool exclude = solve(nums, target, n-1, DP);
            return DP[n][target] = include || exclude;
        }
        else{ 
            return DP[n][target] = solve(nums, target, n-1, DP);
        }

    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
        }
        if(sum % 2 !=0){
            return false;
        }

        int target =  sum / 2;

        vector<vector<int>> DP(n+1, vector<int>(target+1, -1));
        return solve(nums, target, n , DP);
    }
};