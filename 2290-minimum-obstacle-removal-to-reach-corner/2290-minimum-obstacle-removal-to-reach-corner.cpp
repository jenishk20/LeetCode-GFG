class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        
        deque<vector<int>>dq;
        dq.push_back({0,0,0});
        dis[0][0] = 0;
        
        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();
            
            for(int k=0;k<4;k++){
                int nx = dx[k] + curr[0];
                int ny = dy[k] + curr[1];
                
                if(nx>=0 and ny>=0 and nx<n and ny<m and dis[nx][ny] == 1e9){
                    if(grid[nx][ny] == 1){
                        
                        dis[nx][ny] = 1 + curr[2];
                        dq.push_back({nx,ny,dis[nx][ny]});
                    }
                    else{
                        dis[nx][ny] = curr[2];
                        dq.push_front({nx,ny,dis[nx][ny]});
                    }
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};