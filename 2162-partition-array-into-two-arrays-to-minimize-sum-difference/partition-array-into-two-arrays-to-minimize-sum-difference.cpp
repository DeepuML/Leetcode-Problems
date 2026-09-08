class Solution {
public:
    void generate(vector<int>& nums,int index,int end, int count, long long sum, vector<vector<long long>>& subsets) {
        if(index == end) {
            subsets[count].push_back(sum);
            return;
        }
        // Exclude current element
        generate(nums, index + 1, end, count, sum, subsets);

        // Include current element
        generate(nums, index + 1, end, count + 1, sum + nums[index], subsets);
    }

    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        vector<vector<long long>> left(n + 1);
        vector<vector<long long>> right(n + 1);
        // Generate subsets of left half
        generate(nums, 0, n, 0, 0, left);
        // Generate subsets of right half
        generate(nums, n, N, 0, 0, right);
        // Sort right-half sums
        for(int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

       long long total = 0;
        for(int x : nums) {
            total += x;
        }
        long long ans = LLONG_MAX;
        // We need exactly n elements in the first subset. If we take k elements from left, we need n-k from right.
    

        for(int k = 0; k <= n; k++) {
            int need = n - k;
            for(long long leftSum : left[k]) {
                // We want:leftSum + rightSum ≈ total / 2
                long double target =  (long double)total / 2.0 - leftSum;
                auto it = lower_bound(right[need].begin(), right[need].end(), target);

                // Candidate 1
                if(it != right[need].end()) {
                    long long selectedSum =
                        leftSum + *it;
                    long long diff =
                        llabs(total - 2 * selectedSum);
                    ans = min(ans, diff);
                }
                // Candidate 2
                if(it != right[need].begin()) {
                    --it;
                    long long selectedSum = leftSum + *it;
                    long long diff = llabs(total - 2 * selectedSum);
                    ans = min(ans, diff);
                }
            }
        }
        return (int)ans;
    }
};