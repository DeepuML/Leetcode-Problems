class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;

        // Take first k cards
        for(int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        maxsum = lsum;
        // Slowly remove cards from left
        // and add cards from right
        int rightIndex = n - 1;
        for(int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIndex];
            rightIndex--;
           maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};