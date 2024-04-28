class Solution {
public:
    void dfs(vector<int>graph[],int node,vector<int>&vis,vector<int>&subtree)
    {
        vis[node]=1;
        for(auto i:graph[node])
        {
            if(!vis[i])
            {
                dfs(graph,i,vis,subtree);
                subtree[node]+=subtree[i];
            }
        }
    }
    void dfs(int node,int sum,vector<int>&vis,vector<int>&ans,vector<int>graph[],vector<int>&subtree)
    {
        ans[node]=sum;
        vis[node]=1;
        int n=vis.size();
        for(auto i:graph[node])
        {
            if(!vis[i]){
            int tt=sum+(n-subtree[i])-(subtree[i]);
           // cout<<i<<" "<<tt<<endl;
            dfs(i,tt,vis,ans,graph,subtree);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>subtree(n,1),ans(n,0);
        vector<int>graph[n+1];
        int i;
        for(auto i:edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        dfs(graph,0,vis,subtree);
        
        queue<int>q;
        q.push(0);
        vector<int>dis(n,INT_MAX);
        int sum=0;
        dis[0]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto i:graph[curr])
            {
                if(dis[i]>dis[curr]+1)
                {
                    dis[i]=dis[curr]+1;
                    q.push(i);
                }
            }
        }
        for(i=0;i<n;i++){
            sum+=dis[i];
            vis[i]=0;
        }
        
        dfs(0,sum,vis,ans,graph,subtree);
        // cout<<sum<<endl;
        
        return ans;
        
    }
};