class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        vector<pair<int,int>>sortedQueries;
        for(int i=0;i<queries.size();i++){
            sortedQueries.push_back({queries[i],i});
        }

        sort(sortedQueries.begin(),sortedQueries.end());
        vector<int>ans(queries.size(),0);

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0] = 1;

        int points = 0;
        int st = 0;

        for(int i=0;i<queries.size();i++){

            int currVal = sortedQueries[i].first;
            int idx = sortedQueries[i].second;

            while(!pq.empty() and pq.top().first<currVal){
                points++;
                int cx = pq.top().second.first;
                int cy = pq.top().second.second;
                pq.pop();

                for(int k=0;k<4;k++){
                    int nx = dx[k] + cx;
                    int ny = dy[k] + cy;
                    if(nx>=0 and ny>=0 and nx<n and ny<m and !vis[nx][ny]){
                        pq.push({grid[nx][ny],{nx,ny}});
                        vis[nx][ny] = 1;
                    }
                }
            }
            ans[idx] += points;
        }
        return ans;
    }
};