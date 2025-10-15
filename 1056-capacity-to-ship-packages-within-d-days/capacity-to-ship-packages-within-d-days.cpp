class Solution {
public:
    int maximum(vector<int>& weights){
        int ans=INT_MIN;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>ans){
                ans=weights[i];
            }
        }
        return ans;
    }
    int sum1(vector<int>& weights){
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            sum=sum+weights[i];
        }
        return sum;
    }
    int capacity(vector<int>& weights, int capacity){
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+load>capacity){
                days=days+1;
                load=weights[i];
            }
            else{
                load=load+weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=maximum(weights);
        int end=sum1(weights);
        int mid=0;
        int ans=-1;

        while(start<=end){
            mid=(start+end)/2;

            if(capacity(weights, mid) <= days){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};