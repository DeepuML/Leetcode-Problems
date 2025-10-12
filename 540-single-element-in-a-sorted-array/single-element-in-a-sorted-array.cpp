class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     int n=nums.size();
    
     if (n == 1) return nums[0];
     if(nums[0]!=nums[1]){
        return nums[0];
     }   
    
     if(nums[n-1]!=nums[n-2]){
        return nums[n-1];
     }

     int left=1;
     int right=n-2;
     int mid=0;

     while(left<=right){
        mid=(left+right)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }

            // you are on left part and element is in right half then eliminate left
            if((mid % 2 != 0 && nums[mid]==nums[mid-1]) || (mid % 2 == 0 && nums[mid]==nums[mid+1])){
                // eliminate left part 
                left=mid+1;
            }
            // you are on irght half and element is in left half then eliminate right
            //   if((mid % 2 != 0 && arr[mid]==arr[mid+1]) && (mid % 2 == 0 && arr[mid]==arr[mid-1])
            else{
                right=mid-1;
            }
        }
     
     return -1;
}
};