class Solution {

private:
    map<string,multiset<string>>graph;
private:
    void dfs(string s,vector<string>&ans)
    {
        while(graph[s].size()!=0)
        {
            string res=*graph[s].begin();
            graph[s].erase(graph[s].begin());
            dfs(res,ans);
            ans.push_back(res);
            
        }
        
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto it:tickets)
        {
            graph[it[0]].insert(it[1]);
        }
       
        vector<string>ans;
        dfs("JFK",ans);
        reverse(ans.begin(),ans.end());
           ans.insert(ans.begin(),"JFK");
        return ans;
        
        
    }
};