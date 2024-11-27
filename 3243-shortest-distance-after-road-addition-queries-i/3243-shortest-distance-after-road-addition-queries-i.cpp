class Solution {
public:
    
    vector<int>runBFS(int n,int src,vector<int>graph[]){
        vector<int>dis(n+1,1e8);
        queue<int>q;
        q.push(src);
        dis[src] =0 ;
        while(!q.empty()){
            
            auto curr = q.front();
            q.pop();
            
            for(auto it : graph[curr]){
                if(dis[it] > 1 + dis[curr]){
                    dis[it] = 1 + dis[curr];
                    q.push(it);
                }
            }
        }
        return dis;
        
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int>ans;
        
        int i;
        vector<int>graph[n+1];
        
        for(i=0;i<n;i++){
            graph[i].push_back(i+1);
        }
        
        for(auto it : queries){
            
            int u = it[0];
            int v = it[1];
            
            graph[u].push_back(v);
            vector<int>dis = runBFS(n,0,graph);
            ans.push_back(dis[n-1]);
        }
        return ans;
        
    }
};