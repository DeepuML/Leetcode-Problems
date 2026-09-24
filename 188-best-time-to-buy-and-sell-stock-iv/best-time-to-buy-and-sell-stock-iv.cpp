const int BUY=0;
const int SELL=1;
const int N= 1e3;
const int k=200;

int DP[N][k];
class Solution {
public:
    int solve(vector<int> &prices, int idx, int event, int k){
        // bc
        if(idx==prices.size() || event==2*k){
            return 0;
        }
        if(DP[idx][event]!=-1){
            return DP[idx][event];
        }
        // skip the day 
        int ans1 = solve(prices, idx+1, event,k);
        // perform any actions 
        int t_t = event%2 ==0 ? BUY : SELL;
        int ans2= 0;
        if(t_t==BUY){
            ans2 = ans2-prices[idx]  +  solve(prices, idx+1, event+1,k);
        }
        else{
            ans2 = prices[idx] + solve(prices, idx+1, event+1,k);
        }
        return DP[idx][event]= max(ans1, ans2);
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(DP,-1,sizeof(DP));
        return solve(prices,0,0,k);
    }
};