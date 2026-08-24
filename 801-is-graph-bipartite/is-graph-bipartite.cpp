class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);

        for(int i=0;i<v;i++){
            if(color[i] != -1){
                continue;
            }

            queue<int> q;

            color[i]=0;
            q.push(i);

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(int neigh : graph[node]){
                    if(color[neigh]==-1){
                    color[neigh] = 1 - color[node];
                    q.push(neigh);
                    }
                    else if(color[neigh]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};