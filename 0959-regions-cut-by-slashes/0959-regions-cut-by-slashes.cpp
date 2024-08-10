class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 and ny>=0 and nx<grid.size() and ny<grid[0].size()
              and !vis[nx][ny] and grid[i][j]==0)
            {
                dfs(nx,ny,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<int>>&grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int i,j;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int island=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]==0)
                {
                    island++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return island;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>matrix(n*3,vector<int>(n*3,0));

        int i,j;
        int sti = 0, stj = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                // cout<<grid[i][j]<<" ";
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }
        
        return numIslands(matrix);
    }
};