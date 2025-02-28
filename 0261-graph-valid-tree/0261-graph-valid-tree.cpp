class Solution {
public:
    bool dfs(int node,int parent,vector<int>graph[],vector<int>&vis){
        vis[node] = 1;

        for(auto it : graph[node]){
            if(it!=parent and !vis[it]){
                if(dfs(it,node,graph,vis)) return true;
            }
            else if(it!= parent and vis[it]) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>vis(n+1,0);
        vector<int>graph[n+1];

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int c = 1;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                if(dfs(i,-1,graph,vis)) return false;
            }
        }
        return true and c==2;
    }

};