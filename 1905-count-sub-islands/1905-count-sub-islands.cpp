class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&vis,bool &be){
        vis[i][j] = 1;
        if(grid1[i][j] == 0) be = false;
        for(int k=0;k<4;k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if(nx>=0 and ny>=0 and nx<grid1.size() and ny<grid1[0].size() and !vis[nx][ny] and grid2[nx][ny]){
                dfs(nx,ny,grid1,grid2,vis,be);
            }
        }
    }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n = grid1.size();
        int m = grid1[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       
        int i,j;
        int cnt = 0;

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(!vis[i][j] and grid2[i][j]){
                    bool be = true;
                    dfs(i,j,grid1,grid2,vis,be);
                    cnt += be;
                }
            }
        }

        return cnt;

    }
};