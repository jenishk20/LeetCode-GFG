class Solution {
public:
    bool dfs(int node,int color,vector<int>adj[],vector<int>&col){
        col[node] = color;
        cout<<node<<" "<<color<<endl;
        for(auto it:adj[node]){
            if(col[it]==-1){
                if(!dfs(it,color^1,adj,col)) return false;
            }
            else if(col[it] == col[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>adj[n];
        int i;
        for(i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
                
            }
        }
        
        vector<int>col(n,-1);
        
        for(i=0;i<n;i++){
            
            if(col[i]==-1 and !dfs(i,1,adj,col)){
               return false;
            }
        }
        
        return true;
    }
};