#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxElement(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculatetotalhours(vector<int>& piles, int speed){
        long long totalhours = 0;
        for(int i = 0; i < piles.size(); i++){
            totalhours += ceil((double)piles[i] / (double)speed);
        }
        return totalhours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = maxElement(piles);
        int ans = INT_MAX;

        while(start <= end){
            int mid = start + (end - start) / 2;  
            long long totalhours = calculatetotalhours(piles, mid);

            if(totalhours <= h){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};
