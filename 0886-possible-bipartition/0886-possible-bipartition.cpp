class Solution {
public:
    bool dfs(int node,vector<int>graph[],vector<int>&color,vector<int>&vis,int col)
    {
        color[node]=col;
        vis[node]=1;
        for(auto i:graph[node])
        {
            if(!vis[i])
            {
                if(!dfs(i,graph,color,vis,col^1))
                    return false;
            }
            else if(color[i]==col) return false;
                
            
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>graph[n+1];
        vector<int>vis(n+1,0);
        for(auto i:dislikes)
        {
            int u=i[0];
            int v=i[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>color(n+1);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,graph,color,vis,0))
                {
                    return false;
                }
            }
        }
        return  true;
    }
};