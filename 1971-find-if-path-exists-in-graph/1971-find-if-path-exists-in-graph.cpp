class Solution {
public:
    void dfs(int source,int dest,bool &be,vector<int>graph[],vector<int>&vis){
        vis[source] = 1;
        
        if(source == dest) be = true;
        for(auto it:graph[source]){
            if(!vis[it])
                dfs(it,dest,be,graph,vis);
        }
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>graph[n];
        
        for(auto it : edges){
            
            int u = it[0];
            int v = it[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        bool be = false;
        vector<int>vis(n+1,0);
        dfs(source,destination,be,graph,vis);
        return be;
    }
};