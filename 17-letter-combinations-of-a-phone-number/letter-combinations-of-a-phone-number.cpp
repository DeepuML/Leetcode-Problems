class Solution {
public:

    void solve(int idx, string digits, string ans, vector<string>& result) {
        if(idx == digits.size()) {
            result.push_back(ans);
            return;
        }
        // map storage
        vector<string> keypaid = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string choices = keypaid[digits[idx] - '0'];
        // for loop
        for(char ch : choices) {
            ans.push_back(ch);
            solve(idx + 1, digits, ans, result);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) {
            return result;
        }
        solve(0, digits, "", result);
        return result;
    }
};