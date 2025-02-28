class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>graph[]){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]) dfs(it,vis,graph);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<int>vis(n+1,0);
        vector<int>graph[n+1];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int cnt = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,graph);
            }
        }
        return cnt;
    }
};