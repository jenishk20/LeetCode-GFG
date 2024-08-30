class Solution {
public:

    vector<int>runDijkastra(int n,int source, int destination,vector<pair<int,int>>graph[]){
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,source});

        vector<int>dist(n+1,1e9);
        dist[source] = 0;
      
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            for(auto it : graph[curr.second]){
                
                int newDistance = it.second + curr.first;
                if(dist[it.first] > newDistance){
                    dist[it.first] = newDistance;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
    
        
       
        vector<pair<int,int>>graph[n+1];
        vector<int>vis(n+1,0);
       
        
        for(auto it : edges){
          
            if(it[2]!=-1){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                graph[u].push_back({v,wt});
                graph[v].push_back({u,wt});
            }
        }

        auto res = runDijkastra(n,source,destination,graph);
        vector<int>d1 = res;
        int shortestDist = d1[destination];

        if(shortestDist < target) return {};

        bool matchingTarget = (shortestDist == target);

        for(auto &it : edges){
            if(it[2] == -1){
                it[2] = (matchingTarget)? 1e9 : 1;
                if(matchingTarget!=true){
                    graph[it[0]].push_back({it[1],it[2]});
                    graph[it[1]].push_back({it[0],it[2]});
                   d1 = runDijkastra(n,source,destination,graph);
                   int newDist  = d1[destination];

                   if(newDist <= target){
                        matchingTarget = true;
                        it[2] += (target-newDist);
                   }
                }
            }
        }

        if(matchingTarget == false) return {};
        return edges;
    }
};