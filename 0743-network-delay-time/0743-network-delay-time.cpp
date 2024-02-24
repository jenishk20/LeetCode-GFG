class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int sz = times.size();
        
        vector<pair<int,int>>ve[n+1];
        
        for(auto i:times){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            
            ve[u].push_back({v,wt});
        }
        
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,k});
        dis[k] = 0;
        
        while(!pq.empty()){
            auto curr = pq.top();
            //cout<<curr.first<<" "<<curr.second<<endl;
            int distance_till_now = curr.first;
            pq.pop();
            
            for(auto itr:ve[curr.second]){
                
                if(dis[itr.first]>distance_till_now + itr.second){
                    dis[itr.first] = distance_till_now + itr.second;
                    pq.push({dis[itr.first],itr.first});
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dis[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};