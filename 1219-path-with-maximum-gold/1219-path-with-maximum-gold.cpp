class Solution {
public:
    int r,c,ans=0;
    int vis[101][101];
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool isvalid(int x,int y)
    {
        return x>=0 && x<r && y>=0 && y<c && vis[x][y]==0;
    }
    void solve(int x,int y,vector<vector<int>>&grid,int sum)
    {
        ans=max(ans,sum);
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isvalid(nx,ny) && grid[nx][ny]!=0)
            {
                sum+=grid[nx][ny];
                vis[nx][ny]=1;
                solve(nx,ny,grid,sum);
                vis[nx][ny]=0;
                sum-=grid[nx][ny];
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
            
        
        r=grid.size();
        c=grid[0].size();
        memset(vis,0,sizeof(vis));
        int i,j;
        
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]!=0)
                {
                    vis[i][j]=1;
                    solve(i,j,grid,grid[i][j]);
                    vis[i][j]=0;
                }
            }
        }
        return ans;
    }
};