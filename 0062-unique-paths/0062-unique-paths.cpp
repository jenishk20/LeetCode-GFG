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
        
        memset(dp,-1,sizeof dp);
        return recur(m-1,n-1,m,n);
    }
};