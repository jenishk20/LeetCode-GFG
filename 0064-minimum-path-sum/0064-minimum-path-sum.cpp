class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<int>dp(n,0);
        
        int i,j;
        
        
        
        for(i=0;i<m;i++){
            
            vector<int>temp(n,INT_MAX);
            
            for(j=0;j<n;j++){
                
                if(i==0 && j==0) {
                    temp[j] = grid[i][j];
                    continue;
                }
                
                int op1 = INT_MAX, op2 = INT_MAX;
                
                if(i-1>=0) op1 = grid[i][j] + dp[j];
                if(j-1>=0) op2 = grid[i][j] + temp[j-1];
                
                temp[j] = min(op1,op2);
                
            }
            dp = temp;
        }
        
        return dp[n-1];
    
    }
};