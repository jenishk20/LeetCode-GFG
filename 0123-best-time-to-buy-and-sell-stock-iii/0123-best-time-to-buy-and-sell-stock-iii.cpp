class Solution {
public:
    int dp[100001][2][4];
    int recur(int idx,int buy,int cap,int n,vector<int>&prices){
        
        if(idx==n) return 0;
        if(cap == 0) return 0;
        
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        
       
        
        if(buy){
            int op1 = -prices[idx] + recur(idx+1,0,cap,n,prices);
            int op2 = recur(idx+1,1,cap,n,prices);
            
            return dp[idx][buy][cap] = max(op1,op2);
        }
        else{
            
            int op1 = prices[idx] + recur(idx+1,1,cap-1,n,prices);
            int op2 = recur(idx+1,0,cap,n,prices);
            
            return dp[idx][buy][cap] = max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        memset(dp,0,sizeof dp);
        
        int i,j;
        
        for(i=0;i<=2;i++){
            for(j=0;j<=1;j++){
                dp[n][j][i] = 0;
            }
        }
        
        for(i=0;i<=n;i++){
            for(j=0;j<=1;j++){
                dp[i][j][0] = 0;
            }
        }
        
        
        for(i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                    long profit = 0;
                    if(buy){
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][!buy][cap],
                                             dp[i+1][buy][cap]);
                    }
                    else{
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1],
                                             dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
       
    }
};