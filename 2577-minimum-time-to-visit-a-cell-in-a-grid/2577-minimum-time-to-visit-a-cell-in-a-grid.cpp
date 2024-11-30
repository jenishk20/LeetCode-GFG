class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int minimumTime(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] + 1 < grid[0][1] and grid[0][0] + 1 < grid[1][0]) return -1;
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        res[0][0] = 0;
    
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            
            
            if(curr[1] == n-1 and curr[2] == m-1) return res[n-1][m-1];
            
            if(vis[curr[1]][curr[2]]){
                continue;
            }
            
            vis[curr[1]][curr[2]] = 1;
        
          
            for(int k=0;k<4;k++){
                
                int nx = dx[k] + curr[1];
                int ny = dy[k] + curr[2];
                
                if(nx>=0 and ny>=0 and nx<n and ny<m){
                 
                    if(grid[nx][ny]<=curr[0]+1){
                        pq.push({curr[0]+1,nx,ny});
                        res[nx][ny] = curr[0] + 1;
                    }
                    else if((grid[nx][ny]-curr[0])%2==0){
                        pq.push({grid[nx][ny]+1,nx,ny});
                        res[nx][ny] = grid[nx][ny]+1;
                    }
                    else{
                        pq.push({grid[nx][ny],nx,ny});
                        res[nx][ny] = grid[nx][ny] ;
                    }
                    
                    
                }
            }
        }
        
        return -1;
    }
};