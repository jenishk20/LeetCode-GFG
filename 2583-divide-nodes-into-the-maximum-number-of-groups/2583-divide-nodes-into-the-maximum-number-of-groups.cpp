class Solution {
public:
    bool dfs(int node,int col,vector<int>&color,vector<int>&vis,vector<int>graph[]){
        color[node] = col; 
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,1-col,color,vis,graph)) return true;
            }
            else if(color[it] == color[node]) return true;
        }
        return false;
    }
    bool isBipartite(int n,vector<int>graph[]){
        vector<int>vis(n+1,0);
        vector<int>color(n+1,0);

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(dfs(i,-1,color,vis,graph)){
                    return false;
                }
            }
        }
        return true;
    }

    int findMaxBFS(int n,int node,vector<int>graph[]){
        vector<int>vis(n+1,0);
        vis[node] = 1;
        queue<int>q;
        q.push(node);
        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();

                for(auto it : graph[curr]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            level++;
        }
        return level;
    }

    int getMax(int node,vector<int>&vis,vector<int>graph[],vector<int>&dis){
        int cmax = dis[node];
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]){
                cmax = max(cmax,getMax(it,vis,graph,dis));
            }
        }
        return cmax;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        vector<int>graph[(int)1e5+1];

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(!isBipartite(n,graph)) return -1;

        int ans = 0;
        vector<int>vis(n+1,0);
        vector<int>dis(n+1,INT_MAX);

        for(int i=1;i<=n;i++){
            dis[i] = findMaxBFS(n,i,graph);
        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ans += getMax(i,vis,graph,dis);
            }
        }
        return ans;
    }
};