class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_ele = *min_element(begin(nums1), end(nums1));

        if(min_ele % 2 !=0){
            //  all odd 
            return true;
        }
        //  check if we can make all even in nums2 
    for(int i=0;i<nums1.size();i++){
        if(nums1[i] % 2==1){
            return false;
        }
    }
    return true;
    }
};