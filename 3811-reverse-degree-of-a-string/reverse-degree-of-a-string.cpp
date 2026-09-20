class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            int revValue = 'z' - s[i] + 1;
            int posi = i + 1;

            ans = ans + revValue * posi;
        }
    return ans;
    }
    
};