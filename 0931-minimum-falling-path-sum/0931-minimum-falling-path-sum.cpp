class Solution {
public:
    
    int dp[101][101];
    int recur(int i,int j,vector<vector<int>>&matrix,int n,int m){
        
        
        
        if(j<0 || j>=m) return 1e7;
        
        if(i==0) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int op1 = matrix[i][j] + recur(i-1,j,matrix,n,m);
        int op2 = matrix[i][j] + recur(i-1,j-1,matrix,n,m);
        int op3 = matrix[i][j] + recur(i-1,j+1,matrix,n,m);
        
        return dp[i][j] = min({op1,op2,op3});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int minVal = INT_MAX;
        
        memset(dp,-1,sizeof dp);
        
        for(int i=0;i<m;i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0) {
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                
                int op1,op2 = INT_MAX ,op3 = INT_MAX;
                
                 op1 = matrix[i][j] + dp[i-1][j];
                
                if(j-1>=0)
                 op2 = matrix[i][j] + dp[i-1][j-1];
                
                if(j+1<m)
                 op3 = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min({op1,op2,op3});
            }
        }
        
        
        
        
        for(int i=0;i<m;i++){
            
            minVal = min(minVal,dp[n-1][i]);
        }
        
        return minVal;
    }
};