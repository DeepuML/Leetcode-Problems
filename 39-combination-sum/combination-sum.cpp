class Solution {
public:
    void solve(int idx, int sum, vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> ans){
        if(sum==target){
            result.push_back(ans);
            return;
        }

        if(idx==candidates.size() || sum > target){
            return ;
        }
        //  take - > repeatedly
        ans.push_back(candidates[idx]);
        solve(idx, sum+candidates[idx], candidates, target, result, ans);
        ans.pop_back(); 

        //  not take
        solve(idx+1, sum, candidates, target, result, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        int sum = 0;

        solve(0,sum, candidates, target, result, ans);
        return result;
    }
};