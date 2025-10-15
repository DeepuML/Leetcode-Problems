class Solution {
public:
    int maximum(vector<int>& bloomDay){
        int ans = INT_MIN;
        for (int day : bloomDay)
            ans = max(ans, day);
        return ans;
    }

    int minimum(vector<int>& bloomDay){
        int ans = INT_MAX;
        for (int day : bloomDay)
            ans = min(ans, day);
        return ans;
    }

    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0; 
        int bouquets = 0;

        for (int d : bloomDay) {
            if (d <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1; 

        int start = minimum(bloomDay);
        int end = maximum(bloomDay);
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
