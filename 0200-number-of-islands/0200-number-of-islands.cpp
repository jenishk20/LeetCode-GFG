class Solution {
public:
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,int n,int m){
    vis[i][j] = 1;

    for(int k=0;k<4;k++){
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if(nx>=0 and ny>=0 and nx<n and ny<m and !vis[nx][ny] and grid[nx][ny] == '1'){
            dfs(nx,ny,vis,grid,n,m);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    dfs(i,j,vis,grid,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};