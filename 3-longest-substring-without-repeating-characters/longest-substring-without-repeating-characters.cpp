class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int max_len = 0;

        unordered_map<char, int> mp;

        for(int r = 0; r < s.size(); r++) {
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            int len = r - l + 1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};