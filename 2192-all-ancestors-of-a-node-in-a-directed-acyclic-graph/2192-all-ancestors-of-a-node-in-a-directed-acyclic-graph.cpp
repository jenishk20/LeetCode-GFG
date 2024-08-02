class Solution {
public:
    void dfs(int node,int parent,vector<int>&child,vector<int>graph[],vector<int>&vis){
        if(node!=parent) child.push_back(node);
        vis[node] = 1;
        for(auto it : graph[node]){
            if(!vis[it]) dfs(it,node,child,graph,vis);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>ans(n);
        map<int,vector<int>>ma;
        
        vector<int>indegree(n+1,0);
        vector<int>graph[n+1];
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            graph[v].push_back(u);
            indegree[v]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        for(int i=0;i<n;i++){
            vector<int>child;
            vector<int>vis(n+1,0);
            dfs(i,i,child,graph,vis);
            sort(child.begin(),child.end());
            ans[i] = child;
            ma[i] = child;
        }
        
        for(auto it : ma){
            cout<<it.first<<" ";
            for(auto it2 : it.second){
                cout<<it2<<" ";
            }
            cout<<endl;
        }
        
        return ans;
        
    }
};