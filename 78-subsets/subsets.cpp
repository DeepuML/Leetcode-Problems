class Solution {
public:
  void solve(int index , vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums){
    if(index==nums.size()){
        ans.push_back(ds);
        return ;
    }
    // pick
    ds.push_back(nums[index]);
    solve(index+1,ds,ans,nums);
    // remove
    ds.pop_back();
    // not pick
    solve(index+1,ds,ans,nums);
  }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0,ds,ans,nums);
        return ans; 
    }
};