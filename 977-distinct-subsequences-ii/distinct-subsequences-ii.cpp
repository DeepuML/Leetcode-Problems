class Solution { 
public: 
 
    int M = 1000000007; 
    int DP[2001]; 
    vector<int> prev; 

    int solve(int n) {         
        if (n == 0) { 
            return 1; 
        } 
        if (DP[n] != -1) { 
            return DP[n]; 
        } 
        long long total = (2LL * solve(n - 1)) % M; 
        if (prev[n] != 0) { 
            int duplicates = solve(prev[n] - 1); 
            total = (total - duplicates + M) % M; 
        } 
        return DP[n] = total; 
    } 

    int distinctSubseqII(string s) { 
        int n = s.length(); 
        memset(DP, -1, sizeof(DP)); 
        prev.assign(n + 1, 0); 
        vector<int> lastSeen(26, 0); 
        for (int i = 1; i <= n; i++) { 
            int idx = s[i - 1] - 'a'; 
            prev[i] = lastSeen[idx]; 
            lastSeen[idx] = i; 
        } 
        return (solve(n) - 1 + M) % M; 
    } 
};