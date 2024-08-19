class Solution {
public:
    void dfs(int node,vector<int>graph[],vector<int>&vis){
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]) dfs(it,graph,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<int>graph[n+1];
        
        for(int i=0;i<n;i++){
            
            for(auto it : rooms[i]){
                graph[i].push_back(it);
            }
        }
        
        vector<int>vis(n+1,0);
        dfs(0,graph,vis);
        
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        
        return true;
    }
};