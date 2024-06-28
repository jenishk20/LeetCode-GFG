class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        
        vector<long long>indeg(n,0),outdeg(n,0);
        int i;
       
        for(i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            
            indeg[v]++;
            outdeg[u]++;
        }
        map<int,int>ma;
        vector<pair<int,int>>ve;
        for(i=0;i<n;i++)
        {
            ve.push_back({i,indeg[i]+outdeg[i]});
        }
        sort(ve.begin(),ve.end(),[](pair<int,int>&p1,pair<int,int>&p2){
            if(p1.second==p2.second)
                return p1.first<p2.first;
            return p1.second>p2.second;
        });
        map<int,int>assigned;
        int st=n;
        for(auto i:ve)
        {
            assigned[i.first]=st--;
        }
        
        for(i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            ans+=assigned[u]+assigned[v];
        }
       return ans;
    }
};