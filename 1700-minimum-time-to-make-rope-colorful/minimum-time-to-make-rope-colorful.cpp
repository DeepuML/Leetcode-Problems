class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
     int time = 0;
     int prev_max = 0;
    
     for(int i=0;i<colors.size();i++){
        if(i>0 && colors[i]!=colors[i-1]){
            prev_max=0;
        }
        int curr =  neededTime[i];
        time = time + min(prev_max, curr);
        prev_max = max(prev_max, curr);
     }
     return time;

    }
};