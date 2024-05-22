class Solution {
public:
    int dp[1001][2][101];
    int maxProfit(int k, vector<int>& prices) {
                
        int n = prices.size();
        memset(dp,0,sizeof dp);
        
        int i,j;
    
        
        for(i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap = 1;cap<=k;cap++){
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
        return dp[0][1][k];
    }
};