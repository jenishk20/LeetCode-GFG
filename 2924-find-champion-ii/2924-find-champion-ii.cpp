class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n+1,0);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            indegree[v]++;
        }

        int cnt = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                cnt++;
                ans = i;
            }
        }

        return cnt == 1 ? ans : -1;
    }
};