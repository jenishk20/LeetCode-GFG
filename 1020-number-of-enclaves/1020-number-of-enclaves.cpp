class Solution {
    
      private:
        int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&vis){
        vis[i][j] = 1;
        
        for(int k=0;k<4;k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if(nx>=0 and ny>=0 and nx<mat.size() and ny<mat[0].size() and mat[i][j] ==1
            and !vis[nx][ny]){
                dfs(nx,ny,mat,vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& mat) {
         int i,j;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(mat[i][j]==0)
                vis[i][j] = 1;
                else if(i==0 || j==0 || i==n-1 || j==m-1 and 
                        mat[i][j]==1){
                    dfs(i,j,mat,vis);
                }
            }
        }
        int ccnt = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(!vis[i][j])
                ccnt++;
            }
        }
        return ccnt;
        
    }
};