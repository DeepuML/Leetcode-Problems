class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        int scs = 0;
        vector<int> last_seen(26, -1);

        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(last_seen[ch-'a']>=scs){
                count ++;
                scs = i;
            }
            last_seen[ch-'a'] = i;
        }
        return count + 1;
    }
};