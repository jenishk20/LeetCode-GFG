using pii = pair<int,int>;
using piii = pair<int,pii>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pii>ve[n];
        priority_queue<piii,vector<piii>,greater<piii>>q;
        
        
        for(auto i:flights){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            ve[u].push_back({v,wt});
        }
        
        q.push({0,{src,0}});
        
        vector<int>dis(n+1,INT_MAX);
        dis[src] = 0;
        
        while(!q.empty()){
            
            int currStops = q.top().first;
            int node = q.top().second.first;
            int disTillNow = q.top().second.second;
            
            q.pop();
            
            if(currStops > k) continue;
            
            for(auto itr: ve[node]){
                
                if(dis[itr.first] > disTillNow + itr.second && currStops<=k){
                    dis[itr.first] = disTillNow + itr.second;
                    q.push({currStops+1,{itr.first,dis[itr.first]}});
                }
            }
        }
        
        return dis[dst] == INT_MAX ? -1 : dis[dst];
        
    }
};