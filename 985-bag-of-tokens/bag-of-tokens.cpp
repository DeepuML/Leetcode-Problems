class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
        int j= tokens.size()-1;
        int max_score=0;
        int score=0;
        sort(tokens.begin(), tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                power= power-tokens[i];
                score++;
                  i++;
                max_score=max(score, max_score);
                
            }
            else if(score>=1){
                power= power+ tokens[j];
                score= score-1;
                j--;
            }
            else {
                return max_score;
            }
        }
        return max_score;
    }
};