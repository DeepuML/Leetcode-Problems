class Solution {
public:
    vector<int> prefixMax(vector<int> &height) {
        int n = height.size();
        vector<int> prefix(n);
        prefix[0] = height[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        return prefix;
    }

    vector<int> sufixMax(vector<int> &height) {
        int n = height.size();
        vector<int> sufix(n);
        sufix[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufix[i] = max(sufix[i + 1], height[i]);
        }
        return sufix;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefix = prefixMax(height);
        vector<int> sufix = sufixMax(height);

        int total = 0;

        for (int i = 0; i < n; i++) {
            int leftmax = prefix[i];
            int rightmax = sufix[i];

            if (height[i] < leftmax && height[i] < rightmax) {
                total += min(leftmax, rightmax) - height[i];
            }
        }
        return total;
    }
};
