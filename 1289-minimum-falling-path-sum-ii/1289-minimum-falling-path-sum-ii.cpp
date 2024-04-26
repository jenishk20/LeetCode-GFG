class Solution {
public:
    
    int recur(int i,int prev,int n,int m,vector<vector<int>>&grid,
             int dp[][501]){
        
        if(i>=n) return 0;
        
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int minSum = INT_MAX;
        
        for(int k=0;k<m;k++){
            
            if(prev>=0 && k!=prev){
               
                int cost = grid[i][k];
                
                int op1 = cost + recur(i+1,k,n,m,grid,dp);
                
                minSum = min({minSum,op1});
               
            }
        }
        // return minSum;
        return dp[i][prev] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int dp[501][501];
        
        memset(dp,-1,sizeof dp);
        return recur(0,m+1,n,m,grid,dp);
    }
};