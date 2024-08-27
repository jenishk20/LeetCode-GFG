class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<pair<double,double>>graph[n+1];
        int i;

        for(i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }

        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        vector<double>prob(n+1,0);
        prob[start_node] = 1;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
         
            for(auto it : graph[curr.second]){
                double newProb = it.second*curr.first;
                if(prob[it.first]<newProb){
                    prob[it.first] = newProb;
                    pq.push({prob[it.first],it.first});
                }
            }
        }

        return prob[end_node];
    }
};