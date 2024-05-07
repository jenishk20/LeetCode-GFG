class Solution {
public:
    int dp[13][10001];
    int recur(int idx,vector<int>&coins,int amount){
        
        if(idx==0){
            
            if(amount%coins[idx]==0) return amount/coins[idx];
            
            return 1e9;
        }
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        
        int op1 = recur(idx-1,coins,amount);
        int op2 = 1e9;
        
        if(amount>=coins[idx]){
            op2 = 1 + recur(idx,coins,amount-coins[idx]);
        }
        
        return dp[idx][amount] = min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        memset(dp,-1,sizeof dp);
        int ans = recur(n-1,coins,amount);
        return ans == 1e9 ? -1 : ans;
    }
};