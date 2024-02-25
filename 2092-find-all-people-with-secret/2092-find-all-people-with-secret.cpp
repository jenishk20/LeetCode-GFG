using pii = pair<int,int>;
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        
        pq.push({0,0});
        pq.push({0,firstPerson});
        int i;
        
        vector<pii>meet[n];
        
        for(auto i:meetings){
            int u = i[0];
            int v = i[1];
            int time = i[2];
            
            meet[u].push_back({v,time});
            meet[v].push_back({u,time});
        }
     
        
        vector<int>vis(n+1,0);

     
        while(!pq.empty()){
            
            int currTime = pq.top().first;
            int person = pq.top().second;
            pq.pop();
            
            if(vis[person]) continue;
            
            vis[person] = 1;
            for(auto i:meet[person]){
                if(!vis[i.first] && currTime<=i.second){
                    pq.push({i.second,i.first});
                }
            }
        }
        
        vector<int>ans;
        for(i=0;i<n;i++)
        {
            if(vis[i])
                ans.push_back(i);
        }
        return ans;
        
    }
};