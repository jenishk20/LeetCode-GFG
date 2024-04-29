class Solution {
public:
    int dp[101][101][101];
    int recur(int i,int j1,int j2,vector<vector<int>>&grid,int n,int m){
        
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
        
        if(i==n-1){
            
            if(j1==j2) return grid[i][j1];
            
            return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int maxCherries = 0;
        
        for(int dx = -1;dx<=1;dx++){
            for(int dy = -1;dy<=1;dy++){
                
                int newPosX = j1 + dx;
                int newPosY = j2 + dy;
                
               
                int op1 = 0;
                
                if(j1==j2){
                    op1 = grid[i][j1] + recur(i+1,newPosX,newPosY,grid,n,m);    
                }
                else{
                    op1 = grid[i][j1] + grid[i][j2] + recur(i+1,newPosX,newPosY,grid,n,m);  
                }
                
                maxCherries = max(maxCherries,op1);
            }
        }
        return dp[i][j1][j2] = maxCherries;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof dp);
        
        return recur(0,0,m-1,grid,n,m);
    }
};