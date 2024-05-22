class Solution {
public:
    
    int dp[100001][2];
    int recur(int idx,int buy,int n,vector<int>&prices){
        
        if(idx==n) return 0;
        
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        if(buy){
            int op1 = -prices[idx] + recur(idx+1,0,n,prices);
            int op2 = recur(idx+1,1,n,prices);
            
            return dp[idx][buy] = max(op1,op2);
        }
        else{
            
            int op1 = prices[idx] + recur(idx+1,1,n,prices);
            int op2 = recur(idx+1,0,n,prices);
            
            return dp[idx][buy] = max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        memset(dp,-1,sizeof dp);
        
        int i,j;
        
        dp[n][0] = dp[n][1] = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                long profit =0;
                
                if(buy){
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
        
        return recur(0,1,n,prices);
    }
};