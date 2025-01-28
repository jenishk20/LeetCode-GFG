class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int &sum){
        vis[i][j] = 1;
        sum += grid[i][j];
        for(int k = 0;k<4;k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size() and grid[nx][ny]>0 and !vis[nx][ny]){
                dfs(nx,ny,grid,vis,sum);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int i,j;

        vector<vector<int>>vis(n,vector<int>(m,0));
        int res = 0;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                int sum = 0;
                if(grid[i][j]>0){
                    dfs(i,j,grid,vis,sum);
                    res = max(res,sum);
                }
            }
        }
        return res;
    }
};