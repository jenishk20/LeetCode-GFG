class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int>dis(n+1,1e8);
        vector<int>secondMin(n+1,1e8);
        int i;
        dis[1] = 0;

        vector<int>graph[n+1];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<pair<int,int>>q;
        q.push({1,1});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            if(curr.first == n and secondMin[n]!=1e8){
                return secondMin[n];
            }
            
            int distanceTillNow = (curr.second == 1)?dis[curr.first]:secondMin[curr.first];
            
            int checkSignal = distanceTillNow/change;

            if(checkSignal&1){
                distanceTillNow = (checkSignal+1)*change;
            }
            
            for(auto it : graph[curr.first]){
                // cout<<"Here "<<it<<endl;
                if(dis[it] == 1e8){
                    dis[it] = distanceTillNow + time;
                    q.push({it,1});
                }
                else if(secondMin[it] == 1e8 and dis[it]!=distanceTillNow + time){
                   secondMin[it] = distanceTillNow + time;
                   q.push({it,2});
                }
            }
        }
        
        return 0;
        
    }
};