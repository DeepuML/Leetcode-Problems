class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r;
        queue<int> d;
        // Store positions
        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }
        while(!r.empty() && !d.empty()) {
            int r_pos = r.front();
            int d_pos = d.front();
            r.pop();
            d.pop();
            if(r_pos < d_pos) {
                // R bans D
                r.push(r_pos + n);
            }
            else {
                // D bans R
                d.push(d_pos + n);
            }
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};