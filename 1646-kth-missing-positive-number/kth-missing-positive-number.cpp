class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
     int n=arr.size();
     int low=0;
     int end=n-1;
     int mid=0;

     while(low<=end){
        mid=(low+end)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            end=mid-1;
        }
     }
     return low+k;
        
    }
};