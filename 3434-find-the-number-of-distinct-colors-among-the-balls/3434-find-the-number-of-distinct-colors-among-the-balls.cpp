class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        map<int,int>ma;
        int cnt = 0;
        map<int,int>colors;

        for(auto it : queries){
            int u = it[0];
            int v = it[1];

            if(ma.find(u)!=ma.end()){
                colors[ma[u]]--;
                colors[v]++;
                if(colors[ma[u]] == 0) colors.erase(ma[u]);
                ma[u] = v;
            }
            else{
                colors[v]++;
                ma[u] = v;

            }

            ans.push_back(colors.size());
        }
        return ans;
    }
};