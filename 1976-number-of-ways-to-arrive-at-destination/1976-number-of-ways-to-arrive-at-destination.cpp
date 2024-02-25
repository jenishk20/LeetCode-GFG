#define ll long long 
class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int sz=roads.size();
        vector<pair<ll,ll>>graph[n+1];
        const int N=1e9+7;
        const ll inf=1e18;
        int i,j,k;
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        
        vector<ll>dis(n+1,inf);
        vector<ll>dp(n+1,0);
        for(i=0;i<sz;i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        pq.push({0,0});
        dis[0]=0;
        dp[0]=1;
        while(!pq.empty())
        {
            ll curr=pq.top().second;
            ll  wt=pq.top().first;
            pq.pop();
            for(auto &it:graph[curr])
            {
                ll to=it.first;
                ll edgewt=it.second;
                if(dis[to]==wt+edgewt)
                {
                    dp[to]=(dp[to]+dp[curr])%N;
                }
                if(dis[to]>wt+edgewt)
                {
                    dis[to]=edgewt+wt;
                    dp[to]=dp[curr]%N;
                    pq.push({dis[to],to});
                }
            }
        }
       // cout<<dp[n-1]<<endl;
        
        return dp[n-1];
        
    }
};