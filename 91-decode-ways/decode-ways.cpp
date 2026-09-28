const int N = 100;
int DP[N + 1];

class Solution {
public:
    char get_char(int num) { return 'A' + num - 1; }

    int solve(int idx, string s, string ans, vector<string>& result) {
        if (idx == s.size()) {
            return 1;
        }
        if (DP[idx] != -1) {
            return DP[idx];
        }
        int ways = 0;
        // take 1
        if (s[idx] != '0') {
            ways = ways + solve(idx + 1, s, ans, result);
        }
        // take 2
        if (idx + 1 < s.size()) {
            int num = stoi(s.substr(idx, 2));
            if (num >= 10 && num <= 26) {
                ways = ways + solve(idx + 2, s, ans, result);
            }
        }
        return DP[idx] = ways;
    }

    int numDecodings(string s) {
        vector<string> result;
        memset(DP, -1, sizeof(DP));
        return solve(0, s, "", result);
    }
};