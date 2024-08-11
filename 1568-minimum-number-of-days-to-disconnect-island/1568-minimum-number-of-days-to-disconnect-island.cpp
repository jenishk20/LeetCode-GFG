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
              and !vis[nx][ny] and grid[i][j]==1)
            {
                dfs(nx,ny,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int i,j;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int island=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                {
                    island++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        
        int cnt = numIslands(grid);
        if(cnt == 0 || cnt > 1) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int i,j;
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    cnt = numIslands(grid);
                    cout<<cnt<<" "<<endl;
                    if(cnt == 0 || cnt > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};