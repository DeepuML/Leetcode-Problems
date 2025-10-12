class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        int ans=INT_MAX;

        while(start<=end){
            mid=(start+end)/2;
            // left sorted 
            if(nums[start]<=nums[mid]){
                ans=min(ans,nums[start]);
                start=mid+1;
            }
            // right sorted
            else{
                ans=min(ans,nums[mid]);
                end= mid-1;
            }
        }
        return ans;
    }
};