class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        ans[0]=nums[0];
        int i = 0;
       for(int j=1;j<nums.size();j++){
        if(nums[i] != nums[j]){
            i++;
            nums[i]=nums[j];
        }
       }
       return i + 1;
    }
};