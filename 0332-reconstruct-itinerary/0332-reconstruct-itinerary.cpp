class Solution {
public:
    map<string,multiset<string>>graph;
    vector<string>ans;
    void dfs(string curr){

        while(graph[curr].size() != 0){
            string nextToVisit = *graph[curr].begin();
            graph[curr].erase(graph[curr].find(nextToVisit));
            dfs(nextToVisit);
            ans.push_back(nextToVisit);
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it : tickets){
            string u = it[0];
            string v = it[1];
            graph[u].insert(v);
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        ans.insert(ans.begin(),"JFK");
        return ans;
    }
};