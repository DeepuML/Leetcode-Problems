class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char ch : num) {
            while(!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // remove remaining digits if k > 0
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        // build result
        string res = "";
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        // remove leading zeros
        int idx = 0;
        while(idx < res.size() && res[idx] == '0') idx++;
        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }
};
