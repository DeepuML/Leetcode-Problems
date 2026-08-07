class Solution {
public:
    void solve(int node, vector<vector<int>> &isConnected,vector<int> &visited){
        visited[node]=1;
        for(int i=0;i<isConnected.size();i++){
        if(isConnected[node][i]==1 && !visited[i]){
            solve(i,isConnected, visited);
        }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans=0;
        vector<int> visited(n,0);

        for(int i=0;i<n;i++){
           if(!visited[i]){
            ans++;
            solve(i,isConnected,visited);        
           }
        }

           return ans; 
    }
};