class Solution {
public:
    vector<long long>runDijkastra(int totalNodes,int node,vector<pair<int,int>>graph[]){
    
    vector<long long>dis(totalNodes,1e10);
    dis[node] = 0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,node});

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        for(auto it : graph[top.second]){
            if(dis[it.first] > it.second + top.first){
                dis[it.first] = it.second + top.first;
                pq.push({dis[it.first],it.first});
            }
        }
    }
    return dis;
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
          long long ans = 0;
        int n = original.size();

        vector<pair<int,int>>graph[27+1];

        int i,j,k;
        for(i=0;i<n;i++){
            int u = original[i]-'a';
            int v = changed[i] - 'a';
            int wt = cost[i];
            graph[u].push_back({v,wt});
        }

        map<int,vector<long long>>distancesFromNode;

        for(i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(distancesFromNode.find(source[i]-'a') != distancesFromNode.end()){
                     vector<long long>distances = distancesFromNode[source[i]-'a'];
                       if(distances[target[i]-'a'] == 1e10) return -1;
                        ans += distances[target[i]-'a'];
                }
                else{
                    vector<long long>distances = runDijkastra(27,source[i]-'a',graph);
                    if(distances[target[i]-'a'] == 1e10) return -1;
                    ans += distances[target[i]-'a'];
                    distancesFromNode[source[i]-'a'] = distances;
                }
            }
        }
        return ans;
    
    }
};