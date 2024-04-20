class Solution {
public:
    int dx[2] = {1,0};
    int dy[2] = {0,1};
    void dfs(int x,int y,vector<vector<int>>&land,int &r,int &c,
            vector<vector<int>>&vis){
        
        vis[x][y] = 1;
        r = max(r,x);
        c = max(c,y);
        
        for(int k=0;k<2;k++){
            int nx = dx[k] + x;
            int ny = dy[k] + y;

            if(nx>=0 and ny>=0 and nx<land.size() and ny<land[0].size()
              and land[nx][ny] == 1  
               && !vis[nx][ny]){
                  dfs(nx,ny,land,r,c,vis);
              }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        
        vector<vector<int>>ans;
        
        
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int i,j;
        
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                
                vector<pair<int,int>>ve;
                if(land[i][j] == 1 && !vis[i][j]){
                    
                    int r = 0;
                    int c = 0;
                    dfs(i,j,land,r,c,vis);  
                    
                    ans.push_back({i,j,r,c});
                    
                }
            }
        }
        return ans;
        
    }
};