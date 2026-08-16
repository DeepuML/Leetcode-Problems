class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_index=-1; 
        int last_index=-1; 
        int mid ; 

        //  first index 
        int s= 0 ;
        int e = nums.size()-1;
        while(s<=e){
            mid =  s + (e-s)/2  ;
            if(nums[mid] ==target){
                first_index= mid;
                e = mid-1;
            }
            else if(target >  nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1 ;
            }
        }

        s = 0;
        e = nums.size() - 1;
        //  last index 
        while(s<=e){
            mid =  s + (e-s)/2  ;
            if(nums[mid] ==target){
                last_index = mid;
                s =  mid+1;
            }
            else if(target >  nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1 ;
            }
        }

        return {first_index, last_index};
    }
};