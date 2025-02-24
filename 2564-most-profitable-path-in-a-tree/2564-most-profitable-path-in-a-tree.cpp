class Solution {
public:
    map<int,int>cameFrom;
    vector<int>reachTime;
    int res = -1e9;
    void dfs(int node,int parent,vector<int>graph[],int stTime,vector<int>&vis){
        cameFrom[node] = parent;
        vis[node] = 1;
        reachTime[node] = stTime;
        for(auto it : graph[node]){
            if(!vis[it]){
                dfs(it,node,graph,stTime+1,vis);
            }
        }
    }

    void dfs1(int node,vector<int>graph[],vector<int>&bobPath,vector<int>&amount,int currTime,int ans,vector<int>&vis){

        vis[node] = 1;
        if(bobPath[node] > currTime || bobPath[node] == -1){
            ans += amount[node];
        }
        if(bobPath[node] == currTime){
            ans += amount[node]/2;
        }
        bool found = false;
        for(auto it : graph[node]){
            if(!vis[it]){
                found = true;
                dfs1(it,graph,bobPath,amount,currTime+1,ans,vis);
            }
        }
        if(found == false) 
        res = max(res,ans);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

            int n = edges.size();
            vector<int>graph[n+1];
            vector<int>vis(n+1,0);
            reachTime.resize(n+1,0);
            vector<int>bobPath(n+1,-1);

            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            cameFrom[bob] = -1;
            dfs(bob,-1,graph,0,vis);

            int st = 0;
            bobPath[bob] = 0;
            while(st!=bob){
                bobPath[st] = reachTime[st];
                st = cameFrom[st];
            }

            for(int i=0;i<=n;i++) vis[i] = 0;
            dfs1(0,graph,bobPath,amount,0,0,vis);
            return res;

    }
};