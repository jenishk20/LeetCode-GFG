class Solution {
public:
    int dp[3001][5001];
    int recur(int idx,vector<int>&coins,int amount){
        
        if(idx==0){
            
            return (amount%coins[idx]) == 0;
        }
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        
        int op1 = recur(idx-1,coins,amount);
        int op2 = 0;
        
        if(amount>=coins[idx]){
            op2 = recur(idx,coins,amount-coins[idx]);
        }
        
        return dp[idx][amount] = op1 + op2;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof dp);
        return recur(n-1,coins,amount);
        
    }
};