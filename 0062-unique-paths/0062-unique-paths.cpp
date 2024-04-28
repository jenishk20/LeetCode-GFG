class Solution {
public:

    int uniquePaths(int m, int n) {
        
        vector<int>dp(n,0);
        
        int i,j;
        
        
        
        for(i=0;i<m;i++){
            
            vector<int>temp(n,0);
            
            for(j=0;j<n;j++){
                
                if(i==0 && j==0) {
                    temp[j] = 1;
                    continue;
                }
                
                int op1 = 0, op2 = 0;
                
                if(i-1>=0) op1 = dp[j];
                if(j-1>=0) op2 = temp[j-1];
                
                temp[j] = op1 + op2;
                
            }
            dp = temp;
        }
        
        return dp[n-1];
    }
};