class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int i,j;
        priority_queue<pair<int,pair<int,int>>>pq;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                pq.push({grid[i][j],{i,j}});
            }
        }

        long long sum = 0;
        while(k and !pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int row = curr.second.first;
            if(limits[row]>0){
                sum += curr.first;
                limits[row]--;
                k--;
            }
        }
        return sum;
    }
};