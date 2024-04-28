class Solution {
public:
    int dp[201][201];
    int recur(int i,int j,int m,int n){
        if(i<0 || j<0) return 0;
        
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int op1 = recur(i-1,j,m,n);
        int op2 = recur(i,j-1,m,n);
        
        return dp[i][j] = op1+op2;
    }
    int uniquePaths(int m, int n) {
    
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) {dp[i][j] = 1; continue;}
                
                int op1 = 0,op2 = 0;
                
                if(i-1>=0) op1 = dp[i-1][j];
                if(j-1>=0) op2 = dp[i][j-1];
                
                dp[i][j] = op1 + op2;
            }
        }
        return dp[m-1][n-1];
    }
};