class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        const int n = graph.size();
        vector<int>outdegree(n+1,0);
        vector<int>revGraph[n+1];
        queue<int>q;

        for(int i=0;i<graph.size();i++){
            if(graph[i].empty()) continue;
            for(auto it : graph[i]){
                outdegree[i]++;
                revGraph[it].push_back(i);
            }
        }

        for(int i=0;i<n;i++){
            if(outdegree[i] == 0) q.push(i);
        }

        vector<int>ans;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(auto it : revGraph[curr]){
                outdegree[it]--;
                if(outdegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};