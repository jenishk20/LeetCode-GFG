class Solution {
public:
  
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<pair<int,int>>graph[n+1];

        vector<long long>minDist(n,1e17);
        vector<int>countOfWays(n+1,0);

        minDist[0] = 0;
        countOfWays[0] = 1;

        pq.push({0,0});

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            for(auto it : graph[curr.second]){
                if(minDist[it.first] > curr.first + it.second){
                    minDist[it.first] = curr.first + it.second;
                    countOfWays[it.first] = countOfWays[curr.second];
                    pq.push({minDist[it.first],it.first});
                }
                else if(minDist[it.first] == curr.first + it.second){
                    countOfWays[it.first] = (countOfWays[it.first] + countOfWays[curr.second])%mod;
                }
            }
        }

        return countOfWays[n-1];

    }
};