class Solution {
public:
    int dfs(int node,int parent,int currTime,vector<int>&bobDistance,vector<int>&amount,vector<int>graph[],int bobNode){

        int maxI = 0;
        int maxCh = -1e9;

        if(node == bobNode) bobDistance[node] = 0;
        else bobDistance[node] = 1e8;

        for(auto it : graph[node]){
            if(it != parent){
                maxCh = max(maxCh,dfs(it,node,currTime+1,bobDistance,amount,graph,bobNode));
                bobDistance[node] = min(bobDistance[node],bobDistance[it]+1);
            }
        }
        if(bobDistance[node] > currTime){
            maxI += amount[node];
        }
        else if(bobDistance[node] == currTime){
            maxI += (amount[node]/=2);
        }
        if(maxCh == -1e9) return maxI;
        return maxI  + maxCh;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = edges.size();
        vector<int>graph[n+1];

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int stTime = 0;
        vector<int>bobDistance(n+1,1e9);
        return dfs(0,0,stTime,bobDistance,amount,graph,bob);
    }
};