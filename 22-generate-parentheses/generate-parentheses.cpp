class Solution {
public:
    void solve(int open , int close, int n, string& ans, vector<string> &result){
        if(open == n && close == n){
            result.push_back(ans);
            return;
        }
        //  opening bracket  
        if(open<n){
            ans.push_back('(');
            solve(open+1, close, n, ans,result);
            ans.pop_back();
        }
        // closing bracket
        if(open>close){
            ans.push_back(')');
            solve(open, close+1, n, ans,result);
            ans.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string ans;
        vector<string> result;
         solve(0,0,n,ans, result);
         return result ;
        }
};