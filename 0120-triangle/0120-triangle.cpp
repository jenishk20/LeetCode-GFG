class Solution {
public:
    int dp[201][201];
    int recur(int i,int j,int n,vector<vector<int>>&triangle){
        
        if(i==n-1) return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int op1 = triangle[i][j] + recur(i+1,j,n,triangle);
        int op2 = triangle[i][j] + recur(i+1,j+1,n,triangle);
        
        return dp[i][j] = min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        
        // memset(dp,-1,sizeof dp);
        
        for(int i=n-1;i>=0;i--){
            
            for(int j=0;j<triangle[i].size();j++){
                
                if(i==n-1){
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                
                int op1 = triangle[i][j] + dp[i+1][j];
                int op2 = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(op1,op2);
        
            }
        }
        
        return dp[0][0];
    }
};