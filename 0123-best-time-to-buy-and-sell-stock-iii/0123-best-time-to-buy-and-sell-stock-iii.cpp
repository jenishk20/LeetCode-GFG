class Solution {
public:
    int dp[100001][2][3];
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
        memset(dp,-1,sizeof dp);
        return recur(0,1,2,n,prices);
    }
};