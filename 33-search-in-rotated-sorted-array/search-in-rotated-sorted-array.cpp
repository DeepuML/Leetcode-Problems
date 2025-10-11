class Solution {
public:
    int search(vector<int>& nums, int target) {
     int start =0;
     int end=nums.size()-1;
     int mid=0;

     while(start<=end){
        mid=(start+end)/2;
        if(nums[mid]==target){
            return mid;
        }
        // left sorted array
        else if(nums[start]<=nums[mid]){
            if(nums[start]<=target && target<nums[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        // right part sorted => nums[mid]<=nums[end]
        else{
            if(target>nums[mid] && target<=nums[end]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
     }
    return -1;
    }

    
};