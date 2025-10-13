class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end=x;
        int ans=1;

        while(start<=end){
            long long mid=(start + end) / 2;
            long long sqrt=(mid * mid);
            if(sqrt <= x){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};