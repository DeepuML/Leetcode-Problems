class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        //  for loop 
        // for(int i=0;i<n;i++){
        //     if((i==0 || nums[i-1]<nums[i]) && (i==n-1 || nums[i]>nums[i+1])){
        //         return i;
        //     }
        // }

        //  binary search 
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }

        int start=1;
        int end=n-2;
        int mid=0;

        while(start<=end){
            // peak elements => mid
            mid=(start+end)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            // peak elements lies in increasing curve
            else if(nums[mid]>nums[mid-1]){
                start=mid+1;
            }
            // peak element lies in decreasing curve
            // if(arr[mid]>arr[mid+1])
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};