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
        
        vector<long>next(2,0),curr(2,0);
        
        int i,j;
       
        next[0] = next[1] = 0;
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                long profit =0;
                
                if(buy){
                    profit = max(-prices[i] + next[0], next[1]);
                }
                else{
                    profit = max(prices[i] + next[1] , next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
        
    }
};