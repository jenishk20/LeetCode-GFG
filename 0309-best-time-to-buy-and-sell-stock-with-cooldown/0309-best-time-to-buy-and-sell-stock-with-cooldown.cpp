class Solution {
public:
    int dp[5002][2];
    int recur(int idx,int tNo,vector<int>&prices,int n){
        if(idx >= n) return 0;
        
        if(dp[idx][tNo]!=-1) return dp[idx][tNo];
        
        if(tNo){
            int op1 = -prices[idx] + recur(idx+1,0,prices,n);
            int op2 = recur(idx+1,1,prices,n);
            return dp[idx][tNo] = max(op2,op1);
        }
        else{
            int op1 = prices[idx] + recur(idx+2,1,prices,n);
            int op2 = recur(idx+1,0,prices,n);
            return dp[idx][tNo] = max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        memset(dp,0,sizeof dp);
        
        int i,j;
        
        for(i=n-1;i>=0;i--){
            for(int t = 0;t<=1;t++)
            {
                if(t){
                    int op1 = -prices[i] + dp[i+1][0];
                    int op2 = dp[i+1][t];
                    dp[i][t] = max(op2,op1);
                    }
                else{
                    int op1 = +prices[i] + dp[i+2][1];
                    int op2 = dp[i+1][t];
                    dp[i][t] = max(op2,op1);
                }
            }
        }
    
        return dp[0][1];
    }
};