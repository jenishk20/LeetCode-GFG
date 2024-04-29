class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int dp[101][101][101];
        memset(dp,-1,sizeof dp);
        
        int i,j,k;
        
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                
                
            }
        }
        
        
        for(i=n-1;i>=0;i--){
            for(j=0;j<m;j++){
                for(k=0;k<m;k++){
                    
                    if(i==n-1){
                        
                        if(j==k) dp[i][j][k] = grid[i][j];
                        
                        else dp[i][j][k] = grid[i][j] + grid[i][k];
                        
                        continue;
                    }
                    
                    int maxCherries = 0;
        
                    for(int dx = -1;dx<=1;dx++){
                        for(int dy = -1;dy<=1;dy++){

                            int newPosX = j + dx;
                            int newPosY = k + dy;

                            int op1 = 0;
                            
                            if(newPosX>=0 and newPosY>=0 and newPosX<m and newPosY<m)                             {
                                if(j==k){
                                op1 = grid[i][j] + dp[i+1][newPosX][newPosY];
                                }
                                else{

                                op1 = grid[i][j] + grid[i][k] + dp[i+1][newPosX][newPosY];
                                }

                            }
                            
                            maxCherries = max(maxCherries,op1);
                        }
        }
                    
                    dp[i][j][k] = maxCherries;
                    
                    
                }
            }
        }
        
     
       return dp[0][0][m-1];
       
    }
};